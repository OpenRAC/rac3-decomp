#include "common.h"

/* NTSC-U counterpart of func_L01_00335950 (src/levels/shared/L01_003326A8.c) */
extern s32 *D_L01_0021F740[];
extern void func_L01_00458E48(void *, void *, s32, s32);
extern s32 *D_L01_0021F740[];
extern void func_L01_00458E48(void *, void *, s32, s32);

/* localdecomp:start func_L01_00335328 */
extern s32 *D_L01_0021F740[];
s32 func_L01_00335328(u8 *a, u8 *b, u8 *c, u8 *d, s32 t0, u8 *cfg, u8 *vt) {
    extern s32 func_L01_00458AE0(u8 *, s32);
    extern void func_L01_00458E48(void *, void *, s32, s32);
    s32 old;
    if (*(s32 *)(cfg+0x6c) != -1 && b[0x5e] == 0) {
        old=*(s16 *)(d+0x258);
        if (func_L01_00458AE0(c,*(s32 *)(cfg+0x6c))) {
            if (cfg[0x13]==3 || cfg[0x13]==4) {
                s32 *path=D_L01_0021F740[*(s32 *)(cfg+0x6c)];
                if (*(s16 *)(d+0x25a)==0) {
                    func_L01_00458E48(c,path,path[0]-1,0);
                } else {
                    func_L01_00458E48(c,path,0,0);
                }
            } else {
                b[0x5e]=1;
                a[0xbc]=1;
            }
            if (cfg[0x13]==4) a[0xbc]=1;
        } else if (cfg[0x13]==2 || cfg[0x13]==4) {
            if (*(s16 *)(d+0x258)!=old) a[0xbc]=1;
        }
    }
    if (cfg[0x97]==0) {
        (*(void (**)(u8 *,s32,s32))(vt+0x24))(c,0,10);
    } else {
        (*(void (**)(u8 *,s32,s32))(vt+0x20))(c,0,10);
    }
    return 0;
}
/* localdecomp:end func_L01_00335328 */
