#ifndef UI_RENDER_AUTO_CLIP_H_
#define UI_RENDER_AUTO_CLIP_H_

#include "duilib/Core/UiRect.h"

namespace ui 
{

class IRender;
class UILIB_API AutoClip
{
public:
    AutoClip(IRender* pRender, const UiRect& rc, bool bClip = true);
    AutoClip(IRender* pRender, const UiRect& rcRound, float fRoundWidth, float fRoundHeight, bool bClip = true);
    ~AutoClip();

private:
    IRender* m_pRender;
    bool m_bClip;
};

} // namespace ui

#endif // UI_RENDER_AUTO_CLIP_H_
