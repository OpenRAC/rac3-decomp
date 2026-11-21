#include "common.h"

/* localdecomp:start func_L39_00578118 */
#include "vu0.h"
typedef struct {
    long q[12];
} GsLoadImage_00578118 __attribute__((aligned(16)));
typedef struct {
    void *clut;
    void *image;
    s32 unk08[3];
    s32 clutSize;
    s32 imageSize;
    s32 unk1C[4];
    s32 tbp;
    s32 unk30[3];
    s32 tbw;
    s32 unk40[3];
    s32 tw;
    s32 th;
} PifTex_00578118;
typedef struct {
    char unk00[8];
    s32 w;
    s32 h;
    s32 unk10;
    s32 psm;
} PifHeader_00578118;
extern void func_0038CB78(void *, s32, s32);
extern s32 func_00139EA0(GsLoadImage_00578118 *, s16, s16, s16, s16, s16, s16, s16);
extern s32 func_001264E0(s32);
extern s32 func_0013A1C8(GsLoadImage_00578118 *, void *);
extern s32 func_001331A0(s32, s32);

static __inline__ s32 log2dim_00578118(s32 x) {
    return 30 - plzcw_asm(x);
}

void func_L39_00578118(char *data, long *out, int tbp, int cbp) {
    PifTex_00578118 d;
    GsLoadImage_00578118 li;
    PifHeader_00578118 *pif = (PifHeader_00578118 *)data;
    s32 c;

    func_0038CB78(&d, 0, sizeof(d));
    d.clut = (char *)pif + 0x20;
    if (pif->psm == 0) {
        d.clutSize = 0x400;
    } else {
        d.clutSize = 0x200;
    }
    c = cbp >> 8;
    d.tw = log2dim_00578118(pif->w);
    d.th = log2dim_00578118(pif->h);
    d.image = (char *)pif + (d.clutSize + 0x20);
    d.imageSize = pif->w * pif->h;
    func_00139EA0(&li, c, 1, pif->psm, 0, 0, 16, 16);
    func_001264E0(0);
    func_0013A1C8(&li, d.clut);
    func_001331A0(0, 0);
    d.tbw = pif->w >> 6;
    if (d.tbw <= 0) {
        d.tbw = 1;
    }
    d.tbp = tbp >> 8;
    func_00139EA0(&li, d.tbp, d.tbw, 0x1B, 0, 0, pif->w, pif->h);
    func_001264E0(0);
    func_0013A1C8(&li, d.image);
    func_001331A0(0, 0);
    out[0] = (unsigned long)((long)((unsigned long)d.tbp | ((unsigned long)d.tbw << 14)
           | ((unsigned long)0x1B << 20) | ((unsigned long)d.tw << 26))
           | ((long)d.th << 30) | ((long)1 << 34) | ((long)c << 37))
           | ((unsigned long)pif->psm << 51) | ((unsigned long)4 << 61);
    out[1] = 1;
    out[2] = 0;
}
/* localdecomp:end func_L39_00578118 */
