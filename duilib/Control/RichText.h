#ifndef UI_CONTROL_RICHTEXT_H_
#define UI_CONTROL_RICHTEXT_H_

#pragma once

#include "duilib/Core/Control.h"
#include "duilib/Render/IRender.h"

namespace ui 
{
class RichTextSlice
{
public:   
    /** 节点名称
    */
    UiString m_nodeName;

    /** 文字内容
    */
    UiString m_text;

    /** 超链接的URL: "href"
    */
    UiString m_linkUrl;

    /** 文字颜色: "color"
    */
    UiString m_textColor;

    /** 背景颜色: "color"
    */
    UiString m_bgColor;

    /** 字体信息
    */
    UiFont m_fontInfo;

public:
    /** 子节点
    */
    std::vector<RichTextSlice> m_childs;
};

class UILIB_API RichText : public Control
{
public:
    RichText();
    RichText(const RichText& r) = delete;
    RichText& operator=(const RichText& r) = delete;
    virtual ~RichText();

    /// 重写父类方法，提供个性化功能，请参考父类声明
    virtual std::wstring GetType() const override;
    virtual void SetAttribute(const std::wstring& strName, const std::wstring& strValue) override;
    virtual void PaintText(IRender* pRender) override;

    /** 计算文本区域大小（宽和高）
     *  @param [in] szAvailable 可用大小，不包含内边距，不包含外边距
     *  @return 控件的文本估算大小，包含内边距(Box)，不包含外边距
     */
    virtual UiSize EstimateText(UiSize szAvailable) override;

public:
    /** 获取文字内边距
     */
    UiPadding GetTextPadding() const;

    /** 设置文字内边距信息, 函数内部会进行DPI自适应操作
     * @param [in] padding 矩形的四个边值分别代表对应的四个内边距值
     * @param [in] bNeedDpiScale 兼容 DPI 缩放，默认为 true
     */
    void SetTextPadding(UiPadding padding, bool bNeedDpiScale = true);

    /** 获取当前字体ID
     * @return 返回字体ID，该编号在 global.xml 中标识
     */
    std::wstring GetFontId() const;

    /** 设置当前字体ID
     * @param [in] strFontId 要设置的字体ID，该ID可在 global.xml 中存在
     */
    void SetFontId(const std::wstring& strFontId);

    /** 获取默认文本颜色
     */
    std::wstring GetTextColor() const;

    /** 设置默认文本颜色
     */
    void SetTextColor(const std::wstring& sTextColor);

    /** 获取行间距倍数
    */
    float GetRowSpacingMul() const;

    /** 设置行间距倍数
    */
    void SetRowSpacingMul(float fRowSpacingMul);

public:
    /** 设置格式的文本
    * @param [in] richText 带有格式的文本内容
    */
    bool SetRichText(const std::wstring& richText);

    /** 追加一个文本片段
    */
    void AppendTextSlice(const RichTextSlice&& textSlice);

    /** 追加一个文本片段
    */
    void AppendTextSlice(const RichTextSlice& textSlice);

public:
    /** 输出带格式化文本
    */
    std::wstring ToString() const;

private:
    /** 解析格式化文本, 生成解析后的数据结构
    */
    bool ParseText(std::vector<RichTextData>& outTextData) const;

    /** 文本片段解析为绘制结构
    * @param [in] textSlice 文本片段
    * @param [in] parentTextData 父对象信息
    * @param [out] textData 解析后的文本结构
    */
    bool ParseTextSlice(const RichTextSlice& textSlice, 
                        const RichTextData& parentTextData,
                        std::vector<RichTextData>& textData) const;

    /** 输出带格式化文本
    */
    std::wstring ToString(const RichTextSlice& textSlice, const std::wstring& indent) const;

private:
    /** 文本绘制的内边距(分别对应四个边的内边距大小)
    */
    UiPadding16 m_rcTextPadding;

    /** 默认字体
    */
    UiString m_sFontId;

    /** 默认文本颜色
    */
    UiString m_sTextColor;

    /** 文本对齐方式
    */
    uint32_t m_uTextStyle;

    /** 行间距倍数
    */
    float m_fRowSpacingMul;

    /** 绘制的文本内容（解析前）
    */
    std::vector<RichTextSlice> m_textSlice;

    /** 绘制的文本内容（解析后）
    */
    std::vector<RichTextData> m_textData;
};

} // namespace ui

#endif // UI_CONTROL_RICHTEXT_H_
