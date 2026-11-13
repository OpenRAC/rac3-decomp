#include "common.h"

/* NTSC-U counterpart of func_L39_006DF018 (src/levels/39_multiplayer_menu/L39_006DC228.c) */
extern u8 D_001A5E50[];
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;
extern u8 D_001A5E50[];
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;
extern u8 D_001A5E50[];
extern void *D_L39_0024D860;
extern u8 D_001A5E50[];
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;
extern u8 D_001A5E50[];
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;

/* localdecomp:start func_L39_006DC4B8 */
typedef struct { s32 words[13]; } C_006DF018;
typedef struct { char pad[0x18]; s32 busy; char pad2[0x2C]; C_006DF018 data; } R_006DF018;
typedef struct { char pad[0x30]; s32 *id; char pad2[0x14]; void *list; } G_006DF018;
typedef struct { char pad[0x88]; f32 a[4]; f32 b[4]; } P_006DF018;
__asm__(".extern D_L39_0024D860, 16");
extern void *D_L39_0024D860;
extern C_006DF018 D_001A5ED8;
extern f32 D_001A6AD0[];
extern R_006DF018 *func_L39_006D67D0(void *, s32);

void func_L39_006DC4B8(void) {
    G_006DF018 *g = (G_006DF018 *)D_L39_0024D860;
    R_006DF018 *r = func_L39_006D67D0(g->list, *g->id);
    P_006DF018 *p;
    s32 i;

    if (r != 0 && r->busy == 0) {
        D_001A5ED8 = r->data;
        p = (P_006DF018 *)D_001A5E50;
        for (i = 0; i < 4; i++) {
            if (p->a[i] <= 0.0f) {
                p->a[i] = D_001A6AD0[0xE0 / 4];
                p->b[i] = D_001A6AD0[0xDC / 4];
            }
        }
    }
}
/* localdecomp:end func_L39_006DC4B8 */
