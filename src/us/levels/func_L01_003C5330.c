#include "common.h"

/* NTSC-U counterpart of func_L01_003C6BB0 (src/levels/shared/L01_003C64E0.c): 0.02 -> 0.0166667 */
typedef struct {
    u8 pad0[257];
    u8 unk101;
    u8 pad102[1724 - 258];
    s32 unk6BC;
} V3C4E78;
typedef struct {
    u8 pad0[32];
    u8 state;
    u8 pad21[104 - 33];
    V3C4E78 *pVars;
} M3C4E78;
#include "vu0.h"
extern int func_L01_003C3E18(char *, char *);
extern int func_L01_003C3E18(char *, char *);
extern void func_L01_003C5670(s32 unused, u8 *s);
extern int func_L01_003C3E18(char *, char *);
extern void func_L01_00441FB8(M3C4E78 *, s32, s32);
extern void func_L01_003C3A10(M3C4E78 *, V3C4E78 *);
#include "vu0.h"
extern s32 D_001A71A0[];

/* localdecomp:start func_L01_003C5330 */
extern u8 *D_L01_001E0180_003C5330;
extern s32 D_L01_001DF9DC_003C5330;
extern f32 D_L01_001DECCC_003C5330;
__asm__(".extern D_L01_001DECCC_003C5330, 4");
extern s32 D_001A71A0[];

extern void func_L01_003C41F8(M3C4E78 *, V3C4E78 *, s32);
extern void func_L01_003C5F90(M3C4E78 *, V3C4E78 *, s32, s32, s32);
extern void func_L01_003E9588(s32, void *, void *, s32, s32, s32);
extern void func_L01_003C4468(M3C4E78 *, V3C4E78 *);
extern void func_L01_003C4570(M3C4E78 *, V3C4E78 *, s32);
extern void func_L01_00438180(s32);
typedef struct {
    u8 pad0[0xC8];
    f32 fC8;
    u8 padCC[0x104 - 0xCC];
    s32 w104;
    u8 pad108[0x760 - 0x108];
    s32 a[4];
    s32 b[4];
    s32 c[4];
} W_003C6BB0;

s32 func_L01_003C5330(M3C4E78 *obj, s32 idx) {
    V3C4E78 *p = obj->pVars;
    W_003C6BB0 *w = (W_003C6BB0 *)p;
    u8 *e;

    if (idx < 0) {
        idx = func_L01_003C3E18((char *)obj, (char *)p);
    }
    if (w->c[idx] == -1) {
        return 0;
    }
    w->w104 = idx;
    func_L01_003C41F8(obj, p, idx);
    func_L01_003C5F90(obj, p, w->c[idx], w->b[idx], 1);
    w->fC8 = D_L01_001DECCC_003C5330 * 0.0166666675f;
    func_L01_003C3A10(obj, p);
    func_L01_003C5670((s32)obj, (u8 *)p);
    e = D_L01_001E0180_003C5330 + (w->a[idx] << 7);
    func_L01_003E9588(0, e + 0x30, e + 0x70, 4, 0, 0);
    func_L01_003C4468(obj, p);
    func_L01_003C4570(obj, p, 1);
    func_L01_00438180(D_001A71A0[0]);
    D_L01_001DF9DC_003C5330 = 1;
    func_L01_00441FB8(obj, 0xB, -1);
    return 1;
}
/* localdecomp:end func_L01_003C5330 */
