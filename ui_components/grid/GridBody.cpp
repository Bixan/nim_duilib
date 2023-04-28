#include "GridBody.h"
#include "Grid.h"
#include "duilib/Core/Window.h"
#include "duilib/Control/List.h"

#include <sstream>
#include <thread>


namespace ui
{
	int GridBody::_SumIntList(const std::vector<int> &vec){
		int sum = 0;
		for (auto it = vec.cbegin(); it != vec.cend(); it++)
			sum += (*it);
		return sum;
	}
	
	void GridBody::_BeginEditGridItem(GridItem *item)
	{
		int row_index = item->row_index;
		int col_index = item->col_index;
		int posx = 0, posy = 0;
		ASSERT(row_index < (int)m_vLayout.size());
		for (int i = 0; i < row_index; ++i)
			posy += m_vLayout[i];
		ASSERT(col_index < (int)m_hLayout.size());
		for (int j = 0; j < col_index; ++j)
			posx += m_hLayout[j];
		if (item->type == GIT_String || item->type == GIT_Int || item->type == GIT_Double)
		{
			m_pReEdit->SetVisible(true);
			m_pReEdit->SetFixedWidth(m_hLayout[col_index] - 1);
			m_pReEdit->SetFixedHeight(m_vLayout[row_index] - 1);
			m_pReEdit->SetMargin({ posx, posy, 0, 0 });
			m_pReEdit->SetText(item->text);
			m_pReEdit->SetFocus();
			m_pReEdit->SetSelAll();
			m_pReEditGridItem = item;
		}
		else if (item->type == GIT_Combo)
		{
			m_pComboEdit->SetVisible(true);
			m_pComboEdit->SetFixedWidth(m_hLayout[col_index] - 1);
			m_pComboEdit->SetFixedHeight(m_vLayout[row_index] - 1);
			m_pComboEdit->SetMargin({ posx, posy, 0, 0 });

			m_pComboEdit->RemoveAll();
			for (size_t i = 0; i < item->combo_list.size(); i++)
			{
				ui::ListContainerElement *combo_item = new ui::ListContainerElement;
				combo_item->SetFixedHeight(20);
				combo_item->SetText(item->combo_list[i]);
				m_pComboEdit->Add(combo_item);
				if (item->text == item->combo_list[i])
					m_pComboEdit->SelectItem(static_cast<int>(i));
			}
			m_pComboEditGridItem = item;
		}
		else if (item->type == GIT_Date)
		{

		}
	}
	void GridBody::_EndEdit()
	{
		if (m_pComboEditGridItem)
		{
			ASSERT(m_pComboEdit->IsVisible());
			m_pComboEditGridItem = nullptr;
			m_pComboEdit->SetVisible(false);
		}
		if (m_pReEditGridItem)
		{
			ASSERT(m_pReEdit->IsVisible());
			if (m_pReEditGridItem->text != m_pReEdit->GetText())
			{
				m_pReEditGridItem->text = m_pReEdit->GetText();
				SendEvent(kEventTextChange, m_pReEditGridItem->row_index, m_pReEditGridItem->col_index);
			}
			m_pReEdit->SetVisible(false);
			m_pReEditGridItem = nullptr;
		}
	}

	bool GridBody::_GetGridItemByMouse(CPoint pt, CPoint& position, bool fixed)
	{
		int fixed_row_height = GetFixedRowHeight();
		int fixed_col_width = GetFixedColWidth();
		CSize szOff = m_pGrid->GetScrollPos();

		pt.Offset(-m_rcItem.left, -m_rcItem.top);
		ASSERT(pt.x > 0 && pt.y > 0);
		if (pt.x <= 0 || pt.y <= 0)
			return false;
		UiRect rcFixed({ 0, 0, fixed_col_width + 1, fixed_row_height + 1 });
		UiRect rcFixedRow({ fixed_col_width, 0, m_pGrid->GetWidth(), fixed_row_height + 1 });
		UiRect rcFixedCol({ 0, fixed_row_height, fixed_col_width + 1, m_pGrid->GetHeight() });
		if (rcFixed.IsPointIn(pt) || rcFixedRow.IsPointIn(pt) || rcFixedCol.IsPointIn(pt))		//in position of fixed row or fixed col
		{
			bool bFind = false;
			if (fixed)
			{
				int posx = 0, posy = 0;
				if (rcFixed.IsPointIn(pt))			//in position of fixed row or fixed col
					;
				else if (rcFixedRow.IsPointIn(pt))
					posx = -szOff.cx;
				else if (rcFixedCol.IsPointIn(pt))
					posy = -szOff.cy;
				CPoint pt_position;
				for (size_t i = 0; i < (size_t)GetRowCount(); i++)
				{
					posy += m_vLayout[i];
					if (posy >= pt.y)
					{
						for (size_t j = 0; j < (size_t)GetColCount(); j++)
						{
							posx += m_hLayout[j];
							if (posx >= pt.x)
							{
								pt_position.x = static_cast<LONG>(j);
								bFind = true;
								break;
							}
						}
						pt_position.y = static_cast<LONG>(i);
						break;
					}
				}
				ASSERT(bFind);
				if (bFind)
				{
					position = pt_position;
				}
			}
			return bFind;
		}

		bool ret = false;
		//in position normal grid item
		ASSERT(pt.x - fixed_col_width > 0 && pt.y - fixed_row_height > 0 && pt.x < m_pGrid->GetWidth() && pt.y < m_pGrid->GetHeight());
		if (pt.x - fixed_col_width > 0 && pt.y - fixed_row_height > 0 && pt.x < m_pGrid->GetWidth() && pt.y < m_pGrid->GetHeight())	
		{
			CPoint ptOff = pt, pt_position;
			ptOff.Offset(szOff.cx, szOff.cy);
			int posx = 0, posy = 0;

			for (size_t i = 0; i < (size_t)GetRowCount(); i++)
			{
				posy += m_vLayout[i];
				if (posy >= ptOff.y)
				{
					for (size_t j = 0; j < (size_t)GetColCount(); j++)
					{
						posx += m_hLayout[j];
						if (posx >= ptOff.x)
						{
							ret = true;
							pt_position.x = static_cast<LONG>(j);
							break;
						}
					}
					pt_position.y = static_cast<LONG>(i);
					break;
				}
			}
			ASSERT(ret);
			if (ret)
			{
				position = pt_position;
			}
		}
		return ret;
	}

	int GridBody::_GetGridItemTop(int row_index)
	{
		int posy = 0;
		ASSERT(row_index < GetRowCount());
		if (row_index < GetRowCount())
		{
			for (size_t i = 0; i < (size_t)row_index; i++)
			{
				posy += m_vLayout[i];
			}
		}
		return posy;
	}
	int GridBody::_GetGridItemLeft(int col_index)
	{
		int posx = 0;
		ASSERT(col_index < GetColCount());
		if (col_index < GetColCount())
		{
			for (size_t i = 0; i < (size_t)col_index; i++)
			{
				posx += m_hLayout[i];
			}
		}
		return posx;
	}
	UiRect GridBody::_GetGridItemPos(int row_index, int col_index)
	{
		int posx = _GetGridItemLeft(col_index), posy = _GetGridItemTop(row_index);
		return UiRect(posx, posy, posx + m_hLayout[col_index], posy + m_vLayout[row_index]);
	}

	void GridBody::_ClearModifyAndSel()
	{
		_EndEdit();
		m_selRange.Clear();
	}
#if 0
	bool GridBody::_GetPaintRangeRect()
	{
		m_rcPaintRange.left = -1;
		m_rcPaintRange.top = -1;
		m_rcPaintRange.right = -1;
		m_rcPaintRange.bottom = -1;

		CSize szOff = m_pGrid->GetScrollPos();
		int posx = 0;
		int posy = 0;
		int row_count = GetRowCount();
		int col_count = GetColCount();
		int fixed_col_width = GetFixedColWidth();
		int fixed_row_height = GetFixedRowHeight();
		int grid_width = m_pGrid->GetWidth();
		int grid_height = m_pGrid->GetHeight();

		if (fixed_row_height >= grid_height)
		{
			m_rcPaintRange.top = 0;
			posy = 0;
			for (int row = 0; row < m_nFixedRow; row++)
			{
				posy += m_vLayout[row];
				if (posy > grid_height)			//超出grid高度
				{
					m_rcPaintRange.bottom = row;
					break;
				}
			}
		}
		else
		{
			posy = fixed_row_height;
			for (int row = m_nFixedRow; row < row_count; row++)
			{
				if (m_vLayout[row] == 0)
					continue;
				if (m_rcPaintRange.top == -1)
					if (posy + m_vLayout[row] - szOff.cy > fixed_row_height)		//单元格下边线没有超过fixed_row_height
						m_rcPaintRange.top = row;
				posy += m_vLayout[row];
				if (posy - szOff.cy > grid_height)			//超出grid高度
				{
					m_rcPaintRange.bottom = row;
					break;
				}
			}
		}

		if (fixed_col_width >= grid_width)
		{
			m_rcPaintRange.left = 0;
			posx = 0;
			for (int col = 0; col < m_nFixedCol; col++)
			{
				posx += m_hLayout[col];
				if (posx > grid_width)			//超出grid宽度
				{
					m_rcPaintRange.right = col;
					break;
				}
			}
		}
		else
		{
			posx = fixed_col_width;
			for (size_t col = m_nFixedCol; col < col_count; col++)
			{
				if (m_hLayout[col] == 0)
					continue;
				if (m_rcPaintRange.left == -1)
					if (posx + m_hLayout[col] - szOff.cx > fixed_col_width)		//单元格右边线没有超过fixed_col_width
						m_rcPaintRange.left = col;

				posx += m_hLayout[col];
				if (posx - szOff.cx > grid_width)		//超出grid宽度
				{
					m_rcPaintRange.right = col;
					break;
				}
			}
		}
		
		bool ret = m_rcPaintRange.left != -1 && m_rcPaintRange.top != -1 && m_rcPaintRange.right != -1 && m_rcPaintRange.bottom != -1;
		ASSERT(ret);
		return ret;
	}
#endif
	GridBody::GridBody(Grid *pGrid) : m_selRange(this), m_pGrid(pGrid){
		m_vLayout.push_back(m_defaultRowHeight);		//insert header hegith
		m_vecRow.push_back(new GridRow());
		SetFixedHeight(m_defaultRowHeight);
		AddCol(L"行号", 30);
		SetFixedColCount(1);
		SetFixedRowCount(1);

		m_pReEdit = new RichEdit;
		m_pReEdit->SetAttribute(L"class", L"simple");
		m_pReEdit->SetAttribute(L"bkcolor", L"white");
		m_pReEdit->SetAttribute(L"align", L"vcenter");
		m_pReEdit->SetAttribute(L"padding", L"2,0,2,0");
		m_pReEdit->SetVisible(false);
		Add(m_pReEdit);

		m_pComboEdit = new Combo;
		m_pComboEdit->SetAttribute(L"class", L"combo2");
		m_pComboEdit->SetAttribute(L"bkcolor", L"white");
		m_pComboEdit->SetVisible(false);
		m_pComboEdit->AttachSelect(nbase::Bind(&GridBody::OnComboEditSelected, this, std::placeholders::_1));
		Add(m_pComboEdit);

		SetAutoDestroyChild(false);
	};

	int GridBody::GetColCount() const
	{
		ASSERT(m_hLayout.size() == GetHeader()->size());
		return static_cast<int>(m_hLayout.size());
	}
	void GridBody::SetColCount(int count)
	{
#ifdef _DEBUG
		clock_t t1 = clock();
#endif
		ASSERT(m_vecRow.size() > 0 && GetHeader()->size() == m_hLayout.size());
		ASSERT(m_vLayout.size() > 0);
		if (m_vLayout.size() == 0)
			return;
		int col_count = GetColCount();
		int row_count = GetRowCount();
		if (count > col_count)
		{
			int col_index = col_count;
			for (; col_index < count; col_index++)
			{
				GridItemInfo itemInfo(L"", 0, col_index);
				GridItem *item = new GridHeaderItem(&itemInfo);
				GetHeader()->push_back(item);
				m_hLayout.push_back(m_defaultColWidth);
				for (size_t i = 1; i < (size_t)row_count; i++)
				{
					itemInfo.row = static_cast<int>(i);
					m_vecRow[i]->push_back(new GridItem(&itemInfo));
				}
			}

			SetFixedWidth(_SumIntList(m_hLayout));

			OnColumnCountChanged(-1, false);
			Invalidate();
		}
		else if (count < col_count)
		{
			_ClearModifyAndSel();

			std::vector<GridItem*> delay_delete_items;
			for (size_t i = 0; i < (size_t)row_count; i++)
			{
				delay_delete_items.insert(delay_delete_items.end(), m_vecRow[i]->items.begin() + count, m_vecRow[i]->items.end());
				if (i == 0)
				{
					for (size_t j = 0; j < delay_delete_items.size(); j++)
					{
						GridHeaderItem *pHeaderItem = dynamic_cast<GridHeaderItem*>(delay_delete_items[j]);
						if (pHeaderItem && pHeaderItem->control_)
						{
							Remove(pHeaderItem->control_);
						}
					}
					ASSERT(GetCount() == GRIDBODY_CHILD_COUNT);
				}
				m_vecRow[i]->items.erase(m_vecRow[i]->items.begin() + count, m_vecRow[i]->items.end());
			}
			
			//异步回收内存
			std::thread thread_delete([delay_delete_items](){
				int index = 0;
				for (auto it = delay_delete_items.cbegin(); it < delay_delete_items.cend(); it++, index++)
				{
					if (index % 1000 == 0)	//防止cpu卡死
						::Sleep(1);
					delete *it;
				}
			});
			thread_delete.detach();


			if (m_nFixedCol > (size_t)count)
				m_nFixedCol = count;

			m_hLayout.erase(m_hLayout.begin() + count, m_hLayout.end());

			SetFixedWidth(_SumIntList(m_hLayout));

			OnColumnCountChanged(-1, true);
			Invalidate();
		}

#ifdef _DEBUG
		printf("GridBody::SetColCount %dms\n", clock() - t1);
#endif
	}

	int GridBody::GetRowCount() const
	{
		ASSERT(m_vLayout.size() == m_vecRow.size());
		return static_cast<int>(m_vLayout.size());
	}
	void GridBody::SetRowCount(int count)
	{
#ifdef _DEBUG
		clock_t t1 = clock();
#endif
		ASSERT(m_vLayout.size() == m_vecRow.size());
		ASSERT(m_hLayout.size() > 0);
		if (m_hLayout.size() == 0)
			return;
		int row_count = GetRowCount();
		int col_count = GetColCount();
		if (count > row_count)
		{
			m_vecRow.reserve(count + 100);
			int row_index = row_count;
			for (; row_index < count; row_index++)
			{
				GridRow *pRow = new GridRow();
				//GridItem *item_arr = new GridItem[col_count];
				//GridItem *item = item_arr;
				wchar_t buf[16] = {0,};
				for (int col = 0; col < col_count; col++)
				{
					GridItemInfo itemInfo(L"", row_index, col);
					GridItem *item = new GridItem(&itemInfo);
					if (col == 0) {
						_itow_s(static_cast<int>(m_vecRow.size()), buf, 10);
						item->text = buf;
					}
					item->CopyType(GetGridItem(0, col));

					pRow->push_back(item);

					item++;
				}
				m_vecRow.emplace_back(pRow);
				m_vLayout.emplace_back(m_defaultRowHeight);
			}
			
			ASSERT(m_vecRow.size() == m_vLayout.size());
			SetFixedHeight(_SumIntList(m_vLayout));

			m_selRange.Clear();
			Invalidate();
		}
		else if (count < row_count)
		{
			_ClearModifyAndSel();
			ASSERT(m_vLayout.size() == m_vecRow.size());
			if (count < 1)		//header必须保留
				count = 1;
			std::vector<GridRow*> delay_delete_rows;
			delay_delete_rows.insert(delay_delete_rows.begin(), m_vecRow.begin() + count, m_vecRow.end());
			
			//异步回收内存
			std::thread thread_delete([delay_delete_rows](){
				int row_count = (int)delay_delete_rows.size();
				for (int row_index = 0; row_index < row_count; row_index++)
				{
					//if (row_index % 100 == 0)		//防止cpu卡死
					//	::Sleep(1);
					GridRow *grid_row = delay_delete_rows[row_index];
					for (size_t i = 0; i < grid_row->size(); i++)
					{
						delete (*grid_row)[static_cast<int>(i)];
					}
					delete grid_row;
				}
			});
			thread_delete.detach();


			if (m_nFixedRow > (size_t)count)
				m_nFixedRow = count;

			m_vecRow.erase(m_vecRow.begin() + count, m_vecRow.end());
			m_vLayout.erase(m_vLayout.begin() + count, m_vLayout.end());

			SetFixedHeight(_SumIntList(m_vLayout));
			Invalidate();
		}
#ifdef _DEBUG
		printf("GridBody::SetRowCount %dms\n", clock() - t1);
#endif
	}

	int GridBody::GetFixedColCount() const
	{
		return static_cast<int>(m_nFixedCol);
	}
	void GridBody::SetFixedColCount(int fixed)
	{
		ASSERT(fixed <= GetColCount());
		if (fixed <= GetColCount() && fixed != (int)m_nFixedCol)
		{
			m_nFixedCol = fixed;
			m_selRange.Clear();
			Invalidate();
		}
	}

	int GridBody::GetFixedRowCount() const
	{
		return static_cast<int>(m_nFixedRow);
	}
	void GridBody::SetFixedRowCount(int fixed)
	{
		ASSERT(fixed <= GetRowCount());
		if (fixed <= GetRowCount() && fixed != (int)m_nFixedRow)
		{
			m_nFixedRow = fixed;
			m_selRange.Clear();
			Invalidate();
		}
	}

	int GridBody::GetColumnWidth(int col_index) const
	{
		ASSERT(col_index >= 0 && col_index < GetColCount());
		if (col_index >= 0 && col_index < GetColCount())
		{
			return m_hLayout[col_index];
		}
		return -1;
	}
	void GridBody::SetColumnWidth(int col_index, int width)
	{
		ASSERT(col_index >= 0 && col_index < GetColCount());
		if (col_index >= 0 && col_index < GetColCount())
		{
			if (m_hLayout[col_index] != width)
			{
				m_hLayout[col_index] = width;
				SetFixedWidth(_SumIntList(m_hLayout));
				OnColumnWidthChanged(col_index, width);
				Invalidate();
			}
		}
	}

	int GridBody::GetRowHeight(int row_index) const
	{
		ASSERT(row_index >= 0 && row_index < GetRowCount());
		if (row_index >= 0 && row_index < GetRowCount())
		{
			return m_vLayout[row_index];
		}
		return -1;
	}
	void GridBody::SetRowHeight(int row_index, int height)
	{
		ASSERT(row_index >= 0 && row_index < GetRowCount());
		if (row_index >= 0 && row_index < GetRowCount())
		{
			if (m_vLayout[row_index] != height)
			{
				m_vLayout[row_index] = height;
				SetFixedHeight(_SumIntList(m_vLayout));
				/*OnRowHeightChanged(row_index, height);*/
				Invalidate();
			}
		}
	}

	int GridBody::GetHeaderHeight() const
	{
		int height = 0;
		ASSERT(m_vLayout.size() > 0);
		if (m_vLayout.size() > 0)
			height = m_vLayout[0];
		return height;
	}
	void GridBody::SetHeaderHeight(int height)
	{
		ASSERT(m_vLayout.size() > 0);
		if (m_vLayout.size() > 0 && m_vLayout[0] != height)
		{
			m_vLayout[0] = height;
			SetFixedHeight(_SumIntList(m_vLayout));
			Invalidate();
		}
	}

	const std::wstring& GridBody::GetFixedBkColor() const
	{
		return m_strFixedBkColor;
	}

	void GridBody::SetFixedBkColor(const std::wstring& color)
	{
		m_strFixedBkColor = color;
		Invalidate();
	}

	const std::wstring& GridBody::GetSelForeColor() const
	{
		return m_strSelForeColor;
	}

	void GridBody::SetSelForeColor(const std::wstring& color)
	{
		m_strSelForeColor = color;
		Invalidate();
	}

	const std::wstring& GridBody::GetGridLineColor() const
	{
		return m_strGridLineColor;
	}

	void GridBody::SetGridLineColor(const std::wstring& color)
	{
		m_strGridLineColor = color;
		Invalidate();
	}

	int GridBody::GetFixedColWidth() const
	{
		int fixed_width = 0;
		ASSERT(m_nFixedCol <= m_hLayout.size());
		for (size_t i = 0; i < m_nFixedCol; i++)
		{
			fixed_width += m_hLayout[i];
		}
		return fixed_width;
	}
	int GridBody::GetFixedRowHeight() const
	{
		int fixed_height = 0;
		ASSERT(m_nFixedRow <= m_vLayout.size());
		for (size_t i = 0; i < m_nFixedRow; i++)
		{
			fixed_height += m_vLayout[i];
		}
		return fixed_height;
	}

	std::wstring GridBody::GetGridItemText(int row_index, int col_index)
	{
		std::wstring str;
		GridItem *item = GetGridItem(row_index, col_index);
		ASSERT(item);
		if (item)
		{
			str = item->text;
		}
		return str;
	}

	bool GridBody::SetGridItemText(const std::wstring& text, int row_index, int col_index)
	{
		bool ret = false;
		GridItem *item = GetGridItem(row_index, col_index);
		ASSERT(item);
		if (item)
		{
			item->text = text;
			ret = true;
		}
		return ret;
	}

	bool GridBody::IsGridItemFixed(int row_index, int col_index)
	{
		bool ret = false;
		if (row_index < (int)m_nFixedRow || col_index < (int)m_nFixedCol)
			ret = true;
		return ret;
	}

	GridHeaderItem* GridBody::AddCol(std::wstring text, int width)
	{
		ASSERT(m_vecRow.size() > 0 && GetHeader()->size() == m_hLayout.size());
		int col_index = static_cast<int>(GetHeader()->size());

		GridItemInfo itemInfo(text, 0, col_index);
		GridHeaderItem *item = new GridHeaderItem(&itemInfo);
		GetHeader()->push_back(item);
		m_hLayout.push_back(width);
		SetFixedWidth(_SumIntList(m_hLayout));

		itemInfo.txt = L"";
		for (size_t i = 1; i < m_vecRow.size(); i++)
		{
			itemInfo.row = static_cast<int>(i);
			m_vecRow[i]->push_back(new GridItem(&itemInfo));
		}

		OnColumnCountChanged(col_index, false);
		Invalidate();
		return item;
	}

	bool GridBody::AddRow()
	{
		ASSERT(m_hLayout.size() > 0);	//新增行前必须现有列
		if (m_hLayout.size() == 0)
			return false;
		int row_index = static_cast<int>(m_vecRow.size());
		int col_count = static_cast<int>(m_hLayout.size());
		GridRow *pRow = new GridRow();
		wchar_t buf[16] = {0, };
		for (size_t i = 0; i < (size_t)col_count; i++)
		{
			GridItemInfo itemInfo(L"", row_index, static_cast<int>(i));
			if (i == 0) {
				_itow_s(static_cast<int>(m_vecRow.size()), buf, 10);
				itemInfo.txt = buf;
			}
			GridItem *item = new GridItem(&itemInfo);

			pRow->push_back(item);
			item->CopyType(GetGridItem(0, static_cast<int>(i)));
		}

		m_vecRow.push_back(pRow);
		m_vLayout.push_back(m_defaultRowHeight);
		ASSERT(m_vecRow.size() == m_vLayout.size());
		int fixHeight = GetFixedHeight();
		if (fixHeight >= 0)
			SetFixedHeight(fixHeight + m_defaultRowHeight);
		else
			SetFixedHeight(_SumIntList(m_vLayout));

		/*m_selRange.Clear();*/
		Invalidate();
		return true;
	}

	GridHeader* GridBody::GetHeader() const
	{
		GridRow *header = nullptr;
		ASSERT(m_vecRow.size() > 0);
		if (m_vecRow.size() > 0)
			header = m_vecRow[0];
		return header;
	}

	GridItem *GridBody::GetGridItem(int row_index, int col_index)
	{
		ASSERT(GetHeader()->size() == m_hLayout.size() && m_vecRow.size() == m_vLayout.size());
		GridItem *item = nullptr;
		if (row_index >= 0 && row_index < (int)m_vecRow.size() && col_index >= 0 && col_index < (int)m_vecRow[row_index]->size())
		{
			item = m_vecRow[row_index]->at(col_index);
		}
		return item;
	}

	bool GridBody::RemoveRow(int row_index)
	{
		bool ret = false;
		_ClearModifyAndSel();
		ASSERT(m_vLayout.size() == m_vecRow.size());
		row_index--;
		if (row_index > 0 && row_index < (int)m_vecRow.size())
		{
			GridRow *grid_row = m_vecRow[row_index];
			for (size_t i = 0; i < grid_row->size(); i++)
			{
				delete grid_row->at(static_cast<int>(i));
			}
			delete grid_row;
			m_vecRow.erase(m_vecRow.begin() + row_index);
#if 1
			//下面行的GridItem的row_index--
			for (size_t i = row_index; i < m_vecRow.size(); i++)
			{
				GridRow *pRow = m_vecRow[i];
				ASSERT(pRow->at(0)->row_index - 1 == (int)i);
				for (size_t j = 0; j < pRow->size(); j++)
				{
					pRow->at(static_cast<int>(j))->row_index = static_cast<int>(i);
					if (j == 0)
					{
						wchar_t buf[16] = {0, };
						_itow_s(static_cast<int>(i), buf, 10);
						pRow->at(static_cast<int>(j))->text = buf;
					}
				}
			}
#endif
			m_vLayout.erase(m_vLayout.begin() + row_index);

			if (m_nFixedRow > (size_t)row_index)
				m_nFixedRow--;

			SetFixedHeight(_SumIntList(m_vLayout));
			Invalidate();
			ret = true;
		}

		return ret;
	}

	bool GridBody::RemoveCol(int col_index)
	{
		bool ret = false;
		_ClearModifyAndSel();
		ASSERT(m_hLayout.size() == GetHeader()->size());
		col_index--;
		if (col_index > 0 && col_index < (int)GetHeader()->size())
		{
			std::vector<GridItem*> delay_delete_items;
			for (auto it = m_vecRow.begin(); it != m_vecRow.end(); it++)
			{
				GridRow *pRow = *it;
				delay_delete_items.push_back(*(pRow->items.begin() + col_index));
				if (it == m_vecRow.begin())
				{
					GridHeaderItem *pHeaderItem = dynamic_cast<GridHeaderItem*>(delay_delete_items[0]);
					if (pHeaderItem && pHeaderItem->control_)
					{
						Remove(pHeaderItem->control_);
					}
					ASSERT(GetCount() == GRIDBODY_CHILD_COUNT);
				}
				pRow->items.erase(pRow->items.begin() + col_index);
			}
			m_hLayout.erase(m_hLayout.begin() + col_index);

			//异步回收内存
			std::thread thread_delete([delay_delete_items](){
				int index = 0;
				for (auto it = delay_delete_items.cbegin(); it < delay_delete_items.cend(); it++, index++)
				{
					if (index % 1000 == 0)	//防止cpu卡死
						::Sleep(1);
					delete *it;
				}
			});
			thread_delete.detach();
#if 1
			//右边列的GridItem的col_index--
			for (size_t i = 0; i < m_vecRow.size(); i++)
			{
				GridRow *pRow = m_vecRow[i];
				ASSERT(pRow->at(0)->row_index == (int)i);
				for (size_t j = col_index; j < pRow->size(); j++)
				{
					pRow->at(static_cast<int>(j))->col_index--;
				}
			}
#endif
			if (m_nFixedCol > (size_t)col_index)
				m_nFixedCol--;

			SetFixedWidth(_SumIntList(m_hLayout));

			OnColumnCountChanged(col_index, true);
			Invalidate();
			ret = true;
		}

		return ret;
	}

	void GridBody::Clear(bool include_header)
	{
		_ClearModifyAndSel();
		ASSERT(m_vLayout.size() == m_vecRow.size());

		SetRowCount(1);

		if (include_header)		//移除header
		{
			SetColCount(1);
		}
	}

	bool GridBody::AutoFixColWidth(int col_index, int min_width, int max_width)
	{
		if (col_index < 0 || col_index >= GetColCount())
			return false;
		if (max_width != -1 && max_width <= min_width)
			return false;
		int col_width = min_width;
		int row_count = GetRowCount();
		auto pRender = this->m_pWindow->GetRenderContext();
		for (int i = 0; i < row_count; i++)
		{
			GridRow *pRow = m_vecRow[i];
			std::wstring str = pRow->at(col_index)->text;
			if (!str.empty())
			{
				UiRect rcMessure = pRender->MeasureText(str, m_strGridFont, m_uTextStyle, 0);
				int width = rcMessure.right - rcMessure.left + 8;
				if (col_width < width)
					col_width = width;
			}
		}
		if (max_width != -1 && col_width > max_width)
			col_width = max_width;

		SetColumnWidth(col_index, col_width);
		return true;
	}

	const GridSelRange& GridBody::GetSelRange() const
	{
		return m_selRange;
	}

	void GridBody::HandleEvent(const EventArgs& event)
	{
		if (!IsMouseEnabled() && event.Type > kEventMouseBegin && event.Type < kEventMouseEnd) {
			if (m_pParent != NULL) m_pParent->SendEvent(event);
			else Box::HandleEvent(event);
			return;
		}
		bool bHandle = false;
		if (event.Type == kEventInternalDoubleClick)
		{
			OnMouseDoubleClick(event);
			bHandle = true;
		}
		else if (event.Type == kEventMouseMove)
		{
			OnMouseMove(event);
			bHandle = true;
		}
		else if (event.Type == kEventKeyDown)
		{
			OnKeyDown(event);
			bHandle = true;
		}
		if (!bHandle)
			__super::HandleEvent(event);
	}

	bool GridBody::ButtonDown(const EventArgs& msg)
	{
		_EndEdit();
		CPoint position;
		bool ctrl = (msg.wParam & MK_CONTROL);
		bool shift = (msg.wParam& MK_SHIFT);
		bool bFind = _GetGridItemByMouse(CPoint(msg.ptMouse), position, true);
		if (bFind)
		{
			printf("GridBody::ButtonDown item position{%d,%d}\n", position.x, position.y);

			CSize szOff = m_pGrid->GetScrollPos();
			int fixed_col_width = GetFixedColWidth();
			int grid_width = m_pGrid->GetWidth();
			CPoint pt (msg.ptMouse);
			pt.Offset(-m_rcItem.left, -m_rcItem.top);
			ASSERT(pt.x > 0 && pt.y > 0);
			if (pt.x <= 0 || pt.y <= 0 || m_vLayout.size() == 0)
				return true;

			int posx = 0;
			//点击fixed row和fixed col区域
			if (position.x < (LONG)m_nFixedCol && position.y < (LONG)m_nFixedRow)
			{
				if (position.y == 0)
				{
					for (size_t i = 0; i < m_nFixedCol; i++)
					{
						posx += m_hLayout[i];
						if (posx - pt.x >= 0 && posx - pt.x < DRAG_HEADER_OFF_SIZE)
						{
							m_nDragColIndex = static_cast<int>(i);
							m_ptDragColumnStart = pt;
							m_ptDragColumnMoving = pt;
							m_nDrawDragColumnMovingOffX = posx - pt.x;
							Invalidate();
							::SetCursor(::LoadCursor(NULL, IDC_SIZEWE));
							break;
						}
					}
				}
				return true;
			}

			if (position.x < (LONG)m_nFixedCol)			//点击第一列 选择行
			{
				if (position.x == 0){
					m_bDragSel = true;
					m_ptDragSelStart = position;
					m_selRange.SetSelRow(position.y, ctrl, shift);
				}
			}
			else if (position.y < (LONG)m_nFixedRow)		//点击第一行 选择列
			{
				if (position.y == 0)
				{
					bool drag_col = false;
					posx = fixed_col_width;
					for (size_t i = m_nFixedCol; i < m_hLayout.size(); i++)
					{
						posx += m_hLayout[i];
						if (posx - pt.x - szOff.cx >= 0 && posx - pt.x - szOff.cx < DRAG_HEADER_OFF_SIZE)
						{
							m_nDragColIndex = static_cast<int>(i);
							m_ptDragColumnStart = pt;
							m_ptDragColumnMoving = pt;
							m_nDrawDragColumnMovingOffX = posx - pt.x - szOff.cx;
							Invalidate();
							::SetCursor(::LoadCursor(NULL, IDC_SIZEWE));
							drag_col = true;
							break;
						}
						if (posx - szOff.cx > grid_width)	//超出边界了
							break;
					}
					if (!drag_col){
						m_bDragSel = true;
						m_ptDragSelStart = position;
						m_selRange.SetSelCol(position.x, ctrl, shift);
					}
				}
			}
			else{		//点击普通区域
				if (!ctrl && !shift)
				{
					GridItem *pItem = GetGridItem(position.y, position.x);
					if (pItem && pItem->IsSelected())
					{
						_BeginEditGridItem(pItem);
					}
				}
				m_bDragSel = true;
				m_ptDragSelStart = position;
				m_selRange.SetSelItem(position.y, position.x, ctrl, shift);
			}
		}
		else
			ASSERT(0);
		
		return true;
	}

	bool GridBody::ButtonUp(const EventArgs& msg)
	{
		if (m_nDragColIndex != -1)
		{
			ASSERT(m_nDragColIndex < GetColCount());
			CPoint pt(msg.ptMouse);
			pt.Offset(-m_rcItem.left, -m_rcItem.top);
			int width = GetColumnWidth(m_nDragColIndex) + pt.x - m_ptDragColumnStart.x;
			if (width < MIN_COLUMN_WIDTH)
				width = MIN_COLUMN_WIDTH;
			
			SetColumnWidth(m_nDragColIndex, width);
			m_nDragColIndex = -1;
			Invalidate();
		}	

		if (m_bDragSel)
		{
			m_bDragSel = false;
			m_selRange.MergeRange();
		}

		return true;
	}

	bool GridBody::OnMouseDoubleClick(const EventArgs& msg)
	{
		CPoint position;
		bool bFind = _GetGridItemByMouse(CPoint(msg.ptMouse), position);
		if (bFind)
		{
			GridItem *item = GetGridItem(position.y, position.x);
			ASSERT(item);
			if (item)
			{
				wprintf(L"GridBody::OnMouseDoubleClick {%d, %d} %s\n", position.x, position.y, item->text.c_str());
				_BeginEditGridItem(item);
			}
		}
		else
		{
			CSize szOff = m_pGrid->GetScrollPos();
			int fixed_col_width = GetFixedColWidth();

			CPoint pt(msg.ptMouse);

			pt.Offset(-m_rcItem.left, -m_rcItem.top);
			ASSERT(pt.x > 0 && pt.y > 0);
			if (pt.x <= 0 || pt.y <= 0 || m_vLayout.size() == 0)
				return true;
			UiRect rcFixedHeader({ 0, 0, fixed_col_width, m_vLayout[0] });
			UiRect rcHeader({ fixed_col_width, 0, m_pGrid->GetWidth(), m_vLayout[0] });
			int posx = 0;
			if (rcFixedHeader.IsPointIn(pt))
			{
				for (size_t i = 0; i < m_nFixedCol; i++)
				{
					posx += m_hLayout[i];
					if (posx - pt.x >= 0 && posx - pt.x < DRAG_HEADER_OFF_SIZE)
					{
						::SetCursor(::LoadCursor(NULL, IDC_SIZEWE));
						AutoFixColWidth(static_cast<int>(i));
						break;
					}
				}
			}
			else if (rcHeader.IsPointIn(pt))
			{
				posx = fixed_col_width;
				for (size_t i = m_nFixedCol; i < m_hLayout.size(); i++)
				{
					posx += m_hLayout[i];
					if (posx - pt.x - szOff.cx >= 0 && posx - pt.x - szOff.cx< DRAG_HEADER_OFF_SIZE)
					{
						::SetCursor(::LoadCursor(NULL, IDC_SIZEWE));
						AutoFixColWidth(static_cast<int>(i));
						break;
					}
				}
			}
		}
		return true;
	}

	bool GridBody::OnMouseMove(const EventArgs& msg)
	{
		CSize szOff = m_pGrid->GetScrollPos();
		int fixed_col_width = GetFixedColWidth();

		CPoint pt(msg.ptMouse);
		pt.Offset(-m_rcItem.left, -m_rcItem.top);
		//ASSERT(pt.x > 0 && pt.y > 0);
		if (pt.x <= 0 || pt.y <= 0 || m_vLayout.size() == 0)
			return true;
		if ((msg.wParam & MK_LBUTTON) > 0)	//鼠标左键被按下
		{
			if (m_nDragColIndex != -1)			//正在调整列宽
			{
				m_ptDragColumnMoving = pt;
				Invalidate();	
			}
			else if (m_bDragSel)				//正在选择GridItem
			{
				if (pt.x >= m_pGrid->GetWidth() || pt.y >= m_pGrid->GetHeight())		//超出Grid控件位置限制
					return true;
				CPoint position;
				bool ctrl = (msg.wParam & MK_CONTROL);
				bool shift = (msg.wParam& MK_SHIFT);
				bool bFind = _GetGridItemByMouse(CPoint(msg.ptMouse), position, true);
				if (bFind && (position != m_ptDragSelStart || m_bDrageSelChanged))
				{
					if (position != m_ptDragSelStart)
						m_bDrageSelChanged = true;
					else
						m_bDrageSelChanged = false;
					int left = std::min(position.x, m_ptDragSelStart.x);
					int top = std::min(position.y, m_ptDragSelStart.y);
					int right = std::max(position.x, m_ptDragSelStart.x);
					int bottom = std::max(position.y, m_ptDragSelStart.y);
					if (m_ptDragSelStart.x < (LONG)m_nFixedCol && m_ptDragSelStart.x == 0)		//sel row drag
					{
						m_selRange.SetSelRowRange(top, bottom, ctrl, shift);
					}
					else if (m_ptDragSelStart.y < (LONG)m_nFixedRow && m_ptDragSelStart.y == 0)	//sel col drag
					{
						m_selRange.SetSelColRange(left, right, ctrl, shift);
					}
					else
					{
						m_selRange.SetSelItemRange({ left, top, right, bottom }, ctrl, shift);
					}				
				}
			}
			return true;
		}
		UiRect rcFixedHeader({ 0, 0, fixed_col_width, m_vLayout[0] });
		UiRect rcHeader({ fixed_col_width, 0, m_pGrid->GetWidth(), m_vLayout[0] });
		int posx = 0;
		if (rcFixedHeader.IsPointIn(pt))
		{
			for (size_t i = 0; i < m_nFixedCol; i++)
			{
				posx += m_hLayout[i];
				if (posx - pt.x >= 0 && posx - pt.x < DRAG_HEADER_OFF_SIZE)
				{
					::SetCursor(::LoadCursor(NULL, IDC_SIZEWE));
					break;
				}
			}
		}
		else if (rcHeader.IsPointIn(pt))
		{
			posx = fixed_col_width;
			for (size_t i = m_nFixedCol; i < m_hLayout.size(); i++)
			{
				posx += m_hLayout[i];
				if (posx - pt.x - szOff.cx >= 0 && posx - pt.x - szOff.cx< DRAG_HEADER_OFF_SIZE)
				{
					::SetCursor(::LoadCursor(NULL, IDC_SIZEWE));
					break;
				}
			}
		}
		return true;
	}

	bool GridBody::OnKeyDown(const EventArgs& msg)
	{
		bool ctrl = (::GetKeyState(VK_CONTROL) & 0x80) > 0;		//判断CTRL键是否是被按下的状态
		bool shift = (::GetKeyState(VK_SHIFT) & 0x80) > 0;		//判断Shift键是否是被按下的状态
		//printf("GridBody::OnKeyDown %d\n", msg.chKey);
		switch (msg.chKey)
		{
		case VK_LEFT:
		case VK_UP:
		case VK_RIGHT:
		case VK_DOWN:
			m_selRange.MoveSelItem(msg.chKey, ctrl, shift);
			break;
		case VK_DELETE:
			m_selRange.ClearContent();
			break;
		case VK_ESCAPE:
			m_selRange.Clear();
			break;
		case L'A':
			if (ctrl)
				m_selRange.SetSelAll();
			break;
		case L'C':
			if (ctrl)
				m_selRange.CtrlCorX(false);
			break;
		case L'V':
			if (ctrl)
				m_selRange.CtrlV();
			break;
		case L'X':
			if (ctrl)
				m_selRange.CtrlCorX(true);
			break;
		default:
			break;
		}
		return true;
	}

	bool GridBody::OnComboEditSelected(const EventArgs */*args*/)
	{
		if (m_pComboEditGridItem && m_pComboEdit && m_pComboEdit->IsVisible())
		{
			if (m_pComboEditGridItem->text != m_pComboEdit->GetText())
			{
				m_pComboEditGridItem->text = m_pComboEdit->GetText();
				SendEvent(kEventTextChange, m_pComboEditGridItem->row_index, m_pComboEditGridItem->col_index);
			}
		}
		return true;
	}

	void GridBody::PaintChild(IRenderContext* pRender, const UiRect& rcPaint)
	{
		UiRect rcTemp;
		if (!::IntersectRect(&rcTemp, &rcPaint, &m_rcItem)) return;

		for (auto it = m_items.begin(); it != m_items.end(); it++) {
			Control* pControl = *it;
			if (!pControl->IsVisible()) continue;
			/*if (pControl->IsFloat()) {
				pControl->AlphaPaint(pRender, rcPaint);
			}
			else */{
				CSize scrollPos = m_pGrid->GetScrollPos();
				UiRect rcNewPaint = GetPaddingPos();
				rcNewPaint.left += GetFixedColWidth();			
				/*rcNewPaint.top += GetFixedRowHeight();*/		//可能表头存在控件
				if (rcNewPaint.left > rcNewPaint.right) rcNewPaint.left = rcNewPaint.right;
				if (rcNewPaint.top > rcNewPaint.bottom) rcNewPaint.top = rcNewPaint.bottom;
				AutoClip alphaClip(pRender, rcNewPaint, m_bClip);
				rcNewPaint.Offset(scrollPos.cx, scrollPos.cy);
				rcNewPaint.Offset(GetRenderOffset().x, GetRenderOffset().y);

				CPoint ptOffset(scrollPos.cx, scrollPos.cy);
				CPoint ptOldOrg = pRender->OffsetWindowOrg(ptOffset);
				pControl->AlphaPaint(pRender, rcNewPaint);
				pRender->SetWindowOrg(ptOldOrg);
			}
		}
	}

	void GridBody::Paint(IRenderContext* pRender, const UiRect& rcPaint)
	{
		if (!::IntersectRect(&m_rcPaint, &rcPaint, &m_rcItem)) return;

		PaintBkColor(pRender);
		PaintBkImage(pRender);
		PaintStatusColor(pRender);
		PaintStatusImage(pRender);
		//PaintText(pRender);
		PaintBody(pRender);
		PaintBorder(pRender);

	}

	void GridBody::PaintBorder(IRenderContext* pRender)
	{
		__super::PaintBorder(pRender);
		if (m_pGrid->m_bPaintGridLine && m_hLayout.size() > 0 && m_vLayout.size() > 0)
		{
			CSize szOff = m_pGrid->GetScrollPos();
			int posx = 0, posy = 0;
			int fixed_col_width = GetFixedColWidth();
			int fixed_row_height = GetFixedRowHeight();
			int grid_width = m_pGrid->GetWidth();
			int grid_height = m_pGrid->GetHeight();
			UiRect rcLineH, rcLineV;
			DWORD dwGridLineColor = GlobalManager::GetTextColor(m_strGridLineColor);

			CPoint ptOldOrg = pRender->OffsetWindowOrg({ -m_rcItem.left, -m_rcItem.top });
			{
				//draw fixed HLine
				rcLineH.left = 0;
				rcLineH.right = GetFixedWidth() - szOff.cx > grid_width ? grid_width : GetFixedWidth() - szOff.cx;
				ASSERT(m_nFixedRow <= m_vLayout.size());
				for (size_t i = 0; i < m_nFixedRow; i++)
				{
					posy += m_vLayout[i];
					rcLineH.top = rcLineH.bottom = posy - 1;
					pRender->DrawLine(rcLineH, 1, dwGridLineColor);
				}
				//draw HLine
				for (size_t i = m_nFixedRow; i < m_vLayout.size(); i++)
				{
					posy += m_vLayout[i];
					if (posy - szOff.cy > grid_height)	//超出grid高度
						break;
					if (posy - szOff.cy > fixed_row_height && posy - szOff.cy < grid_height)
					{
						rcLineH.top = rcLineH.bottom = posy - szOff.cy - 1;
						pRender->DrawLine(rcLineH, 1, dwGridLineColor);
					}
				}
			
				//draw fixed VLine
				rcLineV.top = 0;
				rcLineV.bottom = GetFixedHeight() - szOff.cy > grid_height ? grid_height : GetFixedHeight() - szOff.cy;
				ASSERT(m_nFixedCol <= m_hLayout.size());
				for (size_t i = 0; i < m_nFixedCol; i++)
				{
					posx += m_hLayout[i];
					rcLineV.left = rcLineV.right = posx - 1;
					pRender->DrawLine(rcLineV, 1, dwGridLineColor);
				}
				//draw VLine
				for (size_t i = m_nFixedCol; i < m_hLayout.size(); i++)
				{
					posx += m_hLayout[i];
					if (posx - szOff.cx > grid_width)		//超出grid宽度
						break;
					if (posx - szOff.cx > fixed_col_width)
					{
						rcLineV.left = rcLineV.right = posx - szOff.cx - 1;
						pRender->DrawLine(rcLineV, 1, dwGridLineColor);
					}
				}

				//draw drag line
				if (m_nDragColIndex != -1)
				{
					int pos = m_ptDragColumnMoving.x + m_nDrawDragColumnMovingOffX;
					UiRect rcLine = { pos, 0, pos, m_pGrid->GetHeight() };
					DWORD dwColorLine = 0x8f888888;
					pRender->DrawLine(rcLine, 2, dwColorLine);
				}
			}
			
			pRender->SetWindowOrg(ptOldOrg);
		}
	}

	void GridBody::PaintBody(IRenderContext* pRender)
	{
		CSize szOff = m_pGrid->GetScrollPos();
		int posx = 0;
		int posy = 0;
		int row_count = GetRowCount();
		int col_count = GetColCount();
		int fixed_col_width = GetFixedColWidth();
		int fixed_row_height = GetFixedRowHeight();
		int grid_width = m_pGrid->GetWidth();
		int grid_height = m_pGrid->GetHeight();
		DWORD dwDefColor = GlobalManager::GetTextColor(L"textdefaultcolor");

		//draw fixed col && fixed row bkcolor
		if (fixed_row_height > 0)
		{
			UiRect rcPaint = GetPos();
			rcPaint.bottom = rcPaint.top + fixed_row_height;
			rcPaint.right = rcPaint.left + (GetFixedWidth() - szOff.cx > grid_width ? grid_width : GetFixedWidth() - szOff.cx);
			pRender->DrawColor(rcPaint, m_strFixedBkColor, 255);
		}
		if (fixed_col_width > 0)
		{
			UiRect rcPaint = GetPos();
			rcPaint.right = rcPaint.left + fixed_col_width;
			rcPaint.bottom = rcPaint.top + (GetFixedHeight() - szOff.cy > grid_height ? grid_height : GetFixedHeight() - szOff.cy);
			pRender->DrawColor(rcPaint, m_strFixedBkColor, 255);
		}

		//draw fixed col && fixed row text
		for (int i = 0; i < (int)m_nFixedRow; i++)
		{
			if (m_vLayout[i] == 0)
				continue;
			posx = 0;
			GridRow *grid_row = m_vecRow[i];
			for (size_t j = 0; j < m_nFixedCol; j++)
			{
				if (m_hLayout[j] == 0)
					continue;
				UiRect rc = { posx, posy, posx + m_hLayout[j], posy + m_vLayout[i] };
				rc.Offset({ m_rcItem.left, m_rcItem.top });
				pRender->DrawText(rc, grid_row->at(static_cast<int>(j))->text, dwDefColor, m_strGridFont, m_uTextStyle, 255, false);
				posx += m_hLayout[j];
			}
			posy += m_vLayout[i];
		}

		//draw fixed row text
		{
			UiRect rcClip = m_pGrid->GetPos();
			rcClip.left += GetFixedColWidth();
			rcClip.bottom = rcClip.top + GetFixedRowHeight();
			AutoClip clip(pRender, rcClip, m_bClip);
			posy = 0;
			for (int i = 0; i < (int)m_nFixedRow; i++)
			{
				if (m_vLayout[i] == 0)
					continue;
				GridRow *grid_row = m_vecRow[i];
				posx = GetFixedColWidth();
				for (size_t j = m_nFixedCol; j < (size_t)col_count; j++)
				{
					if (m_hLayout[j] == 0)
						continue;
					std::wstring str = grid_row->at(static_cast<int>(j))->text;
					if (!str.empty() && posx + m_hLayout[j] - szOff.cx > fixed_col_width)		//单元格右边线没有超过fixed_col_width
					{
						UiRect rc = { posx, posy, posx + m_hLayout[j], posy + m_vLayout[i] };
						rc.Offset({ m_rcItem.left - szOff.cx, m_rcItem.top });
						pRender->DrawText(rc, str, dwDefColor, m_strGridFont, m_uTextStyle, 255, false);
					}
					posx += m_hLayout[j];
					if (posx - szOff.cx > grid_width)	//超出grid宽度
						break;
				}
				posy += m_vLayout[i];
				if (posy - szOff.cy > grid_height)		//超出grid高度
					break;
			}
		}

		//draw fixed col text
		{
			UiRect rcClip = m_pGrid->GetPos();
			rcClip.top += GetFixedRowHeight();
			rcClip.right = rcClip.left + GetFixedColWidth();
			AutoClip clip(pRender, rcClip, m_bClip);
			posx = 0;
			for (int i = 0; i < (int)m_nFixedCol; i++)
			{
				if (m_hLayout[i] == 0)
					continue;
				posy = GetFixedRowHeight();
				for (size_t j = m_nFixedRow; j < (size_t)row_count; j++)
				{
					if (m_vLayout[j] == 0)
						continue;
					GridRow *grid_row = m_vecRow[j];
					std::wstring str = grid_row->at(i)->text;
					if (!str.empty() && posy + m_vLayout[j] - szOff.cy > fixed_row_height)		//单元格下边线没有超过fixed_row_height
					{
						UiRect rc = { posx, posy, posx + m_hLayout[i], posy + m_vLayout[j] };
						rc.Offset({ m_rcItem.left, m_rcItem.top - szOff.cy });
						pRender->DrawText(rc, str, dwDefColor, m_strGridFont, m_uTextStyle, 255, false);
					}
					posy += m_vLayout[j];
					if (posy - szOff.cy > grid_height)	//超出grid高度
						break;
				}
				posx += m_hLayout[i];
				if (posx - szOff.cx > grid_width)		//超出grid宽度
					break;
			}
		}

		//draw other GridItem
		{
			UiRect rcClip = m_pGrid->GetPos();
			rcClip.left += GetFixedColWidth();
			rcClip.top += GetFixedRowHeight();;
			AutoClip clip(pRender, rcClip, m_bClip);
			posy = GetFixedRowHeight();
			for (int i = static_cast<int>(m_nFixedRow); i < row_count; i++)
			{
				if (m_vLayout[i] == 0)
					continue;
				if (posy + m_vLayout[i] - szOff.cy > fixed_row_height)		//单元格下边线没有超过fixed_row_height
				{
					GridRow *grid_row = m_vecRow[i];
					posx = GetFixedColWidth();
					for (size_t j = m_nFixedCol; j < (size_t)col_count; j++)
					{
						if (m_hLayout[j] == 0)
							continue;
						GridItem *pItem = grid_row->at(static_cast<int>(j));

						UiRect rc = { posx, posy, posx + m_hLayout[j], posy + m_vLayout[i] };
						rc.Offset({ m_rcItem.left - szOff.cx, m_rcItem.top - szOff.cy });
						rc.Deflate({ 1, 1, 2, 2 });
						//绘制单元格背景色
						if (pItem->IsSelected())
						{
							pRender->DrawColor(rc, m_strSelForeColor, 255);
						}
						else if (!pItem->bk_color.empty())
						{
							pRender->DrawColor(rc, pItem->bk_color, 255);
						}

						//绘制text
						std::wstring str = pItem->text;
						if (!str.empty() && posx + m_hLayout[j] - szOff.cx > fixed_col_width)		//单元格右边线没有超过fixed_col_width
						{
							if (pItem->text_color.empty() && pItem->text_style == 0)
								pRender->DrawText(rc, str, dwDefColor, m_strGridFont, m_uTextStyle, 255, false);
							else{
								DWORD dwColor = (pItem->text_color.empty() ? dwDefColor : GlobalManager::GetTextColor(pItem->text_color));
								UINT text_style = (pItem->text_style == 0 ? m_uTextStyle : pItem->text_style);
								pRender->DrawText(rc, str, dwColor, m_strGridFont, text_style, 255, false);
							}
						}
						posx += m_hLayout[j];
						if (posx - szOff.cx > grid_width)		//超出grid宽度
							break;
					}
				}
				posy += m_vLayout[i];
				if (posy - szOff.cy > grid_height)			//超出grid高度
					break;
			}
		}
	}

	void GridBody::_SelItem(int row_index, int col_index, bool selected)
	{
		GridItem *pItem = GetGridItem(row_index, col_index);
		ASSERT(pItem);
		if (pItem)
			pItem->SetSelected(selected);
	}
	void GridBody::_SelRow(int row_index, bool selected)
	{
		ASSERT(row_index >= (int)m_nFixedRow && row_index < GetRowCount());
		if (row_index >= (int)m_nFixedRow && row_index < GetRowCount())
		{
			GridRow *pRow = m_vecRow[row_index];
			int row_size = static_cast<int>(pRow->size());
			for (int i = 0; i < row_size; i++)
			{
				pRow->at(i)->SetSelected(selected);
			}
		}
	}
	void GridBody::_SelCol(int col_index, bool selected)
	{
		ASSERT(col_index >= 0 && col_index < GetColCount());
		if (col_index >= 0 && col_index < GetColCount())
		{
			int row_count = GetRowCount();
			for (int i = 0; i < row_count; i++)
			{
				GridRow *pRow = m_vecRow[i];
				pRow->at(col_index)->SetSelected(selected);
			}
		}
	}
	void GridBody::_SelRange(const UiRect& rc, bool selected)
	{
		int row_count = GetRowCount();
		int col_count = GetColCount();
		int left = rc.left;
		int top = rc.top;
		int right = (rc.right < col_count ? rc.right : col_count - 1);
		int bottom = (rc.bottom < row_count ? rc.bottom : row_count - 1);

		for (int row = top; row <= bottom; row++)
		{
			GridRow *pRow = m_vecRow[row];
			for (int col = left; col <= right; col++)
			{
				pRow->at(col)->SetSelected(selected);
			}
		}
	}
}