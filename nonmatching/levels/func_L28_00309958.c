/* near miss (level 28, Opus): 4 diff with the file's flags; see nonmatching/README.md */
#include "common.h"

/* localdecomp:start func_L28_00309958 */
extern s32 func_L28_00309928(void);
typedef struct {
    u8 b[16];
} V16_309958;

__asm__(".extern D_L28_001DC560, 4");
__asm__(".extern D_L28_001DC544, 4");
__asm__(".extern D_L28_001DC564, 4");
__asm__(".extern D_L28_001DC568, 4");
__asm__(".extern D_L28_001DC56C, 4");
__asm__(".extern D_L28_001DC540, 4");
__asm__(".extern D_L28_001DC538, 4");
__asm__(".extern D_L28_001DC554, 4");
__asm__(".extern D_L28_001DC558, 4");
extern u8 *D_L28_001DC560;
extern f32 D_L28_001DC544;
extern s32 D_L28_001DC564;
extern s32 D_L28_001DC568;
extern f32 D_L28_001DC56C;
extern f32 D_L28_001DC540;
extern f32 D_L28_001DC538;
extern s32 D_L28_001DC554;
extern s32 D_L28_001DC558;
extern u8 *D_L28_001D67C8;
extern s32 D_001D4BC4;
extern f32 D_L28_001DFE24;
extern s32 D_L28_001DFE20;
extern V16_309958 D_L28_001DC570[];
extern char D_L28_001DC580[];
extern void func_L01_004C5DC8(void);
extern void func_L24_00402798(void);
extern void func_L24_00402808(void);
extern void func_L24_004027C8(void);
extern void *func_003ABDD8(void *, s32);
extern void func_003AA320(void *, s32, f32, f32, f32, f32, f32);
extern s32 func_00396968(s32, s32);
extern void func_00396E50(s32, s32, s32, s32, s32, void *);
extern s32 func_0011B2E8(char *, char *, ...);
extern s32 func_0011B868(char *);
extern void func_L01_00412858(s32, s32, unsigned long, char *, s32);

static __inline__ s32 func_L28_00309958_scr(f32 v, f32 off) {
    return v * D_L28_001DFE24 + 0.5f + (D_L28_001DFE20 == 1 ? off : 0.0f);
}

s32 func_L28_00309958(void) {
    V16_309958 box;
    char text[16];
    u8 *st;
    f32 sz;
    f32 half;
    f32 y;
    s32 q;
    s32 w;
    void *s;

    st = *(u8 **)(D_L28_001DC560 + 0x68);
    func_L01_004C5DC8();
    sz = 32.0f;
    *(f32 *)(st + 4) += D_L28_001DC544 * 1.2f;
    if (1.0f < *(f32 *)(st + 4)) {
        *(f32 *)(st + 4) = 1.0f;
    }
    if (D_L28_001D67C8 != 0) {
        func_L24_00402798();
        func_L24_00402808();
        s = func_003ABDD8(D_L28_001D67C8 + 0x7090, 0x77);
        func_003AA320(s, 0x411465B7, D_L28_001DC564, func_L28_00309958_scr(D_L28_001DC568, 0.0f), 1.0f, 1.0f, D_L28_001DC56C);
        s = func_003ABDD8(D_L28_001D67C8 + 0x7090, 0x76);
        func_003AA320(s, 0x462299DE, D_L28_001DC564, func_L28_00309958_scr(D_L28_001DC568, 0.0f), 1.0f, 1.0f, D_L28_001DC56C);
        func_L24_004027C8();
    }
    half = sz * (1.0f - *(f32 *)(st + 4)) * 0.5f;
    y = D_001D4BC4 - func_L28_00309958_scr(D_L28_001DC540, 0.0f);
    box = D_L28_001DC570[0];
    q = func_00396968(0xEAA2, func_L28_00309928());
    w = sz * *(f32 *)(st + 4);
    func_00396E50(q, D_L28_001DC538 + half, y, w, func_L28_00309958_scr(w, 0.0f), &box);
    func_0011B2E8(text, D_L28_001DC580, *(s32 *)st);
    func_L01_00412858(D_L28_001DC538 + D_L28_001DC554, (s32)y + func_L28_00309958_scr(D_L28_001DC558, 4.0f),
                      0x80F0F0F0, text, func_0011B868(text));
    return 0;
}
/* localdecomp:end func_L28_00309958 */
