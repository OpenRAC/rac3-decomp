#include "common.h"

/* localdecomp:start func_L39_00689E60 */
typedef struct {
    u8 pad0[0x18];
    s32 f18;
} Rec_L39_00689E60;
typedef struct {
    u8 pad0[0x130];
    s32 f130;
} Sub_L39_00689E60;
typedef struct {
    u8 pad0[0x30];
    Sub_L39_00689E60 *f30;
    u8 pad34[0x14];
    void *f48;
    u8 pad4C[8];
    void *f54;
} G_L39_00689E60;
typedef struct {
    u8 pad0[0x338];
    s32 f338;
} Menu_L39_00689E60;

extern G_L39_00689E60 *D_L39_0024D860;
extern G_L39_00689E60 *D_001E1FD0_sda;
__asm__(".extern D_L39_0024D860, 16");
__asm__(".extern D_L39_00247A74, 16");
__asm__(".extern D_001E1FD0_sda, 4");
extern u8 D_L39_001FC84D[];
extern void *D_L39_00247A74;
extern Rec_L39_00689E60 *func_L39_006D7138_00689E60(void *, u8 *);
extern void func_0011D534(void *, s32, s32);
extern void func_00120D28(void *, void *, s32);
extern char *func_0037DF98(s32);
extern void func_L39_00684930(void *, char *, void *, s32, s32, s32, s32);
extern void func_L39_00686F20(void *, char *);
extern s32 func_L39_006CA3F8(void *, u8 *, void *);
extern void func_L39_006DA8D8(void *);
extern void func_L39_006CA198(void *);

s32 func_L39_00689E60(Menu_L39_00689E60 *obj, s32 idx) {
    u8 local[0x20];
    s32 off = idx * 0x1F0;
    u8 *entry = D_L39_001FC84D + off;
    Rec_L39_00689E60 *rec;
    s32 ok;
    s32 ret;

    obj->f338++;
    rec = func_L39_006D7138_00689E60(D_L39_0024D860->f48, entry);
    ok = 0;
    if (rec != 0) {
        ok = rec->f18 >= 0;
    }
    if ((u8)ok == 0) {
        return 1;
    }
    func_0011D534(local, 0, 0x11);
    if (*(D_L39_001FC84D + 0x33 + off) & 1) {
        func_00120D28(local, D_L39_001FC84D + 0x20 + off, 0x10);
    } else {
        void *p = D_L39_00247A74;

        func_L39_00684930(p, func_0037DF98(0x1183), local, 3, 0x11, 0, 0);
    }
    func_L39_00686F20(obj, func_0037DF98(0xF73));
    ret = func_L39_006CA3F8(D_L39_0024D860->f30, entry, local);
    if (ret == 0) {
        if (D_001E1FD0_sda->f30->f130 == -0x3D2) {
            func_L39_00686F20(obj, func_0037DF98(0x12D0));
            func_L39_006DA8D8(D_L39_0024D860->f54);
            func_L39_006CA198(D_L39_0024D860->f30);
        } else {
            func_L39_00686F20(obj, func_0037DF98(0xF75));
        }
    } else {
        func_L39_00686F20(obj, func_0037DF98(0xF74));
    }
    obj->f338--;
    return ret;
}
/* localdecomp:end func_L39_00689E60 */
