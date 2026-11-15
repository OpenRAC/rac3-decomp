#include "common.h"

/* localdecomp:start func_L39_004BB898 */
extern s32 D_L39_004433B8[];
extern s32 D_L39_004433BC[];
__asm__(".extern D_L39_004433B8, 8");
__asm__(".extern D_L39_004433BC, 8");

s32 func_L39_004BB898(s32 idx, s32 val) {
    s32 ret = 1;

    switch (idx) {
    case 0:
        D_L39_004433B8[0] = val;
        break;
    case 1:
        D_L39_004433BC[0] = val;
        break;
    default:
        ret = 0;
        break;
    }
    return ret;
}
/* localdecomp:end func_L39_004BB898 */

/* localdecomp:start func_L39_004BB8C8 */
extern s32 D_L39_004433C0[];
extern s32 D_L39_004433C4[];
extern s32 (*D_L39_004433C8[])(void);
extern s32 D_L39_004433CC[];
extern s32 (*D_L39_004433D0[])(void);
extern s32 (*D_L39_004433D4[])(void);
extern s32 D_L39_004433D8[];
extern s32 (*D_L39_004433DC[])(void);
extern s32 D_L39_004433E0[];
extern s32 (*D_L39_004433E4[])(void);
extern s32 (*D_L39_004433E8[])(void);
extern s32 (*D_L39_004433EC[])(void);
extern s32 D_L39_004433F0[];
extern s32 D_L39_004433F4[];
extern s32 D_L39_004433F8[];
extern s32 D_L39_004433FC[];
extern s32 D_L39_00443400[];
extern s32 D_L39_00443404[];
extern s32 D_L39_00443408[];
extern s32 (*D_L39_0044340C[])(void);
extern s32 D_L39_00443410[];
extern s32 D_L39_00443414[];
extern s32 D_L39_00443418[];
extern s32 (*D_L39_0044341C[])(void);
extern s32 (*D_L39_00443420[])(void);
extern s32 D_L39_00443424[];
extern s32 (*D_L39_0044342C[])(void);
extern s32 D_L39_00443430[];
extern s32 D_L39_00443434[];
extern s32 D_L39_00443438[];
extern s32 D_L39_0044343C[];
extern s32 (*D_L39_00443428[])(void);
extern s32 (*D_L39_00443440[])(void);
extern s32 D_L39_00443444[];
extern s32 D_L39_00443448[];
extern s32 D_L39_0044344C[];
extern s32 (*D_L39_00443450[])(void);
extern s32 (*D_L39_00443454[])(void);
extern s32 D_L39_00443458[];
extern s32 D_L39_0044345C[];
extern s32 D_L39_00443460[];
extern s32 D_L39_00443464[];
extern s32 D_L39_00443468[];
extern s32 D_L39_0044346C[];
extern s32 D_L39_00443470[];
extern s32 D_L39_00443480[];
extern s32 (*D_L39_0044347C[])(void);
extern s32 D_L39_00443484[];
extern s32 (*D_L39_00443474[])(void);
extern s32 (*D_L39_00443478[])(void);
extern s32 D_L39_00443488[];
extern s32 D_L39_0044348C[];
extern s32 D_L39_00443490[];
extern s32 (*D_L39_00443494[])(void);
extern s32 D_L39_00443498[];
__asm__(".extern D_L39_004433C0, 8");
__asm__(".extern D_L39_004433C4, 8");
__asm__(".extern D_L39_004433C8, 16");
__asm__(".extern D_L39_004433CC, 8");
__asm__(".extern D_L39_004433D0, 16");
__asm__(".extern D_L39_004433D4, 16");
__asm__(".extern D_L39_004433D8, 8");
__asm__(".extern D_L39_004433DC, 16");
__asm__(".extern D_L39_004433E0, 8");
__asm__(".extern D_L39_004433E4, 16");
__asm__(".extern D_L39_004433E8, 16");
__asm__(".extern D_L39_004433EC, 16");
__asm__(".extern D_L39_004433F0, 8");
__asm__(".extern D_L39_004433F4, 8");
__asm__(".extern D_L39_004433F8, 8");
__asm__(".extern D_L39_004433FC, 8");
__asm__(".extern D_L39_00443400, 8");
__asm__(".extern D_L39_00443404, 8");
__asm__(".extern D_L39_00443408, 8");
__asm__(".extern D_L39_0044340C, 16");
__asm__(".extern D_L39_00443410, 8");
__asm__(".extern D_L39_00443414, 8");
__asm__(".extern D_L39_00443418, 8");
__asm__(".extern D_L39_0044341C, 16");
__asm__(".extern D_L39_00443420, 16");
__asm__(".extern D_L39_00443424, 8");
__asm__(".extern D_L39_0044342C, 16");
__asm__(".extern D_L39_00443430, 8");
__asm__(".extern D_L39_00443434, 8");
__asm__(".extern D_L39_00443438, 8");
__asm__(".extern D_L39_0044343C, 8");
__asm__(".extern D_L39_00443428, 16");
__asm__(".extern D_L39_00443440, 16");
__asm__(".extern D_L39_00443444, 8");
__asm__(".extern D_L39_00443448, 8");
__asm__(".extern D_L39_0044344C, 8");
__asm__(".extern D_L39_00443450, 16");
__asm__(".extern D_L39_00443454, 16");
__asm__(".extern D_L39_00443458, 8");
__asm__(".extern D_L39_0044345C, 8");
__asm__(".extern D_L39_00443460, 8");
__asm__(".extern D_L39_00443464, 8");
__asm__(".extern D_L39_00443468, 8");
__asm__(".extern D_L39_0044346C, 8");
__asm__(".extern D_L39_00443470, 8");
__asm__(".extern D_L39_00443480, 8");
__asm__(".extern D_L39_0044347C, 16");
__asm__(".extern D_L39_00443484, 8");
__asm__(".extern D_L39_00443474, 16");
__asm__(".extern D_L39_00443478, 16");
__asm__(".extern D_L39_00443488, 8");
__asm__(".extern D_L39_0044348C, 8");
__asm__(".extern D_L39_00443490, 8");
__asm__(".extern D_L39_00443494, 16");
__asm__(".extern D_L39_00443498, 8");

s32 func_L39_004BB8C8(s32 idx, s32 val) {
    s32 ret = 1;

    switch (idx) {
    case 1:
        D_L39_004433C0[0] = val;
        break;
    case 2:
        D_L39_004433C4[0] = val;
        break;
    case 3:
        D_L39_004433C8[0] = (s32 (*)(void))val;
        break;
    case 4:
        D_L39_004433CC[0] = val;
        break;
    case 5:
        D_L39_004433D0[0] = (s32 (*)(void))val;
        break;
    case 6:
        D_L39_004433D4[0] = (s32 (*)(void))val;
        break;
    case 7:
        D_L39_004433D8[0] = val;
        break;
    case 8:
        D_L39_004433DC[0] = (s32 (*)(void))val;
        break;
    case 9:
        D_L39_004433E0[0] = val;
        break;
    case 10:
        D_L39_004433E4[0] = (s32 (*)(void))val;
        break;
    case 11:
        D_L39_004433E8[0] = (s32 (*)(void))val;
        break;
    case 12:
        D_L39_004433EC[0] = (s32 (*)(void))val;
        break;
    case 13:
        D_L39_004433F0[0] = val;
        break;
    case 14:
        D_L39_004433F4[0] = val;
        break;
    case 15:
        D_L39_004433F8[0] = val;
        break;
    case 16:
        D_L39_004433FC[0] = val;
        break;
    case 17:
        D_L39_00443400[0] = val;
        break;
    case 18:
        D_L39_00443404[0] = val;
        break;
    case 19:
        D_L39_00443408[0] = val;
        break;
    case 21:
        D_L39_0044340C[0] = (s32 (*)(void))val;
        break;
    case 22:
        D_L39_00443410[0] = val;
        break;
    case 31:
        D_L39_00443414[0] = val;
        break;
    case 23:
        D_L39_00443418[0] = val;
        break;
    case 24:
        D_L39_0044341C[0] = (s32 (*)(void))val;
        break;
    case 25:
        D_L39_00443420[0] = (s32 (*)(void))val;
        break;
    case 26:
        D_L39_00443424[0] = val;
        break;
    case 35:
        D_L39_0044342C[0] = (s32 (*)(void))val;
        break;
    case 36:
        D_L39_00443430[0] = val;
        break;
    case 37:
        D_L39_00443434[0] = val;
        break;
    case 38:
        D_L39_00443438[0] = val;
        break;
    case 39:
        D_L39_0044343C[0] = val;
        break;
    case 27:
        D_L39_00443428[0] = (s32 (*)(void))val;
        break;
    case 40:
        D_L39_00443440[0] = (s32 (*)(void))val;
        break;
    case 41:
        D_L39_00443444[0] = val;
        break;
    case 42:
        D_L39_00443448[0] = val;
        break;
    case 43:
        D_L39_0044344C[0] = val;
        break;
    case 44:
        D_L39_00443450[0] = (s32 (*)(void))val;
        break;
    case 45:
        D_L39_00443454[0] = (s32 (*)(void))val;
        break;
    case 46:
        D_L39_00443458[0] = val;
        break;
    case 47:
        D_L39_0044345C[0] = val;
        break;
    case 48:
        D_L39_00443460[0] = val;
        break;
    case 49:
        D_L39_00443464[0] = val;
        break;
    case 50:
        D_L39_00443468[0] = val;
        break;
    case 59:
        D_L39_0044346C[0] = val;
        break;
    case 28:
        D_L39_00443470[0] = val;
        break;
    case 33:
        D_L39_00443480[0] = val;
        break;
    case 32:
        D_L39_0044347C[0] = (s32 (*)(void))val;
        break;
    case 34:
        D_L39_00443484[0] = val;
        break;
    case 29:
        D_L39_00443474[0] = (s32 (*)(void))val;
        break;
    case 30:
        D_L39_00443478[0] = (s32 (*)(void))val;
        break;
    case 52:
        D_L39_00443488[0] = val;
        break;
    case 53:
        D_L39_0044348C[0] = val;
        break;
    case 51:
        D_L39_00443490[0] = val;
        break;
    case 54:
        D_L39_00443494[0] = (s32 (*)(void))val;
        break;
    case 55:
        D_L39_00443498[0] = val;
        break;
    default:
        ret = 0;
        break;
    }
    return ret;
}
/* localdecomp:end func_L39_004BB8C8 */
