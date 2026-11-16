/* PAL near miss (Codex wave 7): near miss: 265 words differ with the file's flags.
 * Worker's note: 266 diff; best actual diff build/codex/w357/func_L01_00479AB0.check.5.log. Branch-derived PAL state comparisons preserved in func_L01_00479AB0.s (no jump table). Compiler cross-jumps repeated color/scale updates, unlike retail repeated blocks; three alternate ...
 */
#include "common.h"
/* localdecomp:start func_L01_00479AB0 */
extern s32 D_L01_001D806C,D_L01_001D8070,D_L01_001D8068;
extern f32 D_L01_001D8060;
__asm__(".extern D_L01_001D8060, 4");
__asm__(".extern D_L01_001D8068, 4");
void func_L01_00479AB0(void) {
    extern void func_L01_005170B8(s32,u32);
    extern void func_L01_00517538(s32,f32,f32);
    u8 *hero=D_001A4BE0;
    u32 color=0x70000000 | (D_L01_001D806C<<8) | (D_L01_001D8070<<16) | D_L01_001D8068;
    if(*(s32 *)(hero+0x230)!=0) {
        if(*(s32 *)(hero+0x230)<4) D_L01_001D8060-=0.3f;
        else if(*(s32 *)(hero+0x230)==51) {
            D_L01_001D806C+=30;
            D_L01_001D8070+=30;
            D_L01_001D8060+=0.1f;
        }
        else if((u32)(*(s32 *)(hero+0x230)-46)<5) {
            D_L01_001D806C-=30;
            D_L01_001D8070-=30;
            D_L01_001D8060-=0.1f;
        }
        else if((u32)(*(s32 *)(hero+0x230)-43)<3) {
            D_L01_001D806C+=30;
            D_L01_001D8070+=30;
            D_L01_001D8060+=0.1f;
        }
        else if(*(s32 *)(hero+0x230)==101) {
            D_L01_001D806C+=30;
            D_L01_001D8070+=30;
            D_L01_001D8060+=0.1f;
        }
        else if((u32)(*(s32 *)(hero+0x230)-96)<5) {
            D_L01_001D806C-=30;
            D_L01_001D8070-=30;
            D_L01_001D8060-=0.1f;
        }
        else if((u32)(*(s32 *)(hero+0x230)-93)<3) {
            D_L01_001D806C+=30;
            D_L01_001D8070+=30;
            D_L01_001D8060+=0.1f;
        }
        else if(*(s32 *)(hero+0x230)==151) {
            D_L01_001D806C+=30;
            D_L01_001D8070+=30;
            D_L01_001D8060+=0.1f;
        }
        else if((u32)(*(s32 *)(hero+0x230)-146)<5) {
            D_L01_001D806C-=30;
            D_L01_001D8070-=30;
            D_L01_001D8060-=0.1f;
        }
        else if((u32)(*(s32 *)(hero+0x230)-143)<3) {
            D_L01_001D806C+=30;
            D_L01_001D8070+=30;
            D_L01_001D8060+=0.1f;
        }
        else if(*(s32 *)(hero+0x230)==201) {
            D_L01_001D806C+=30;
            D_L01_001D8070+=30;
            D_L01_001D8060+=0.1f;
        }
        else if((u32)(*(s32 *)(hero+0x230)-196)<5) {
            D_L01_001D806C-=30;
            D_L01_001D8070-=30;
            D_L01_001D8060-=0.1f;
        }
        else if((u32)(*(s32 *)(hero+0x230)-193)<3) {
            D_L01_001D806C+=30;
            D_L01_001D8070+=30;
            D_L01_001D8060+=0.1f;
        }
        else if(*(s32 *)(hero+0x230)==251) {
            D_L01_001D806C+=30;
            D_L01_001D8070+=30;
            D_L01_001D8060+=0.1f;
        }
        else if((u32)(*(s32 *)(hero+0x230)-246)<5) {
            D_L01_001D806C-=30;
            D_L01_001D8070-=30;
            D_L01_001D8060-=0.1f;
        }
        else if((u32)(*(s32 *)(hero+0x230)-243)<3) {
            D_L01_001D806C+=30;
            D_L01_001D8070+=30;
            D_L01_001D8060+=0.1f;
        }
        else goto reset;
    } else {
reset:
        D_L01_001D8060=1.5f;
        D_L01_001D8068=255;
        D_L01_001D806C=213;
        D_L01_001D8070=127;
    }
    func_L01_005170B8(0x10007,color);
    func_L01_00517538(0x10007,D_L01_001D8060,D_L01_001D8060);
}
/* localdecomp:end func_L01_00479AB0 */
