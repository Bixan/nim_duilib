/**@brief 封装Cef浏览器对象为duilib控件
 * @copyright (c) 2016, NetEase Inc. All rights reserved
 * @author Redrain
 * @date 2016/7/19
 */
#ifndef UI_CEF_CONTROL_CEF_NATIVE_CONTROL_H_
#define UI_CEF_CONTROL_CEF_NATIVE_CONTROL_H_

#include "CefControl.h"

namespace ui {

/** duilib的CEF控件，窗口模式
*/
class CefControlNative : public CefControl
{
    typedef CefControl BaseClass;
public:
    explicit CefControlNative(ui::Window* pWindow);
    virtual ~CefControlNative(void) override;

    virtual void Init() override;
    virtual void SetPos(ui::UiRect rc) override;
    virtual void HandleEvent(const ui::EventArgs& msg) override;
    virtual void SetVisible(bool bVisible) override;
    virtual void SetWindow(ui::Window* pWindow) override;

protected:
    /** 重新创建Browser对象
    */
    virtual void ReCreateBrowser() override;

    /** 更新控件的位置(在Browser控件创建成功后调用)
    */
    virtual void UpdateWindowPos() override;
};
}

#endif //UI_CEF_CONTROL_CEF_NATIVE_CONTROL_H_
