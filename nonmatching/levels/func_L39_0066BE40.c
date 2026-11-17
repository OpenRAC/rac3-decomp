/* NTSC-U draft (2026-11-14, Claude worker): C of func_L39_00669538, the NTSC-U twin of func_L39_0066BE40, with NTSC-U names
 * and addresses. Near miss on NTSC-U: 3 words differ with its file's flags.
 */
#include "common.h"

/* NTSC-U counterpart of func_L39_0066BB58 (src/levels/shared/L39_0066BB58.c) */
/* localdecomp:start func_L39_00669538 */
typedef struct {
    void *w0;
    u8 pad4[0x18];
    struct Obj_00669538 *obj;
    u8 pad20[0x8];
    void (*f28)(void *);
    void (*f2C)(void);
    u8 b30;
    u8 b31;
    u8 pad32[0x12];
} E_00669538;
typedef struct Obj_00669538 {
    u8 pad0[0x10];
    f32 x, y, z;
    u8 pad1C[0x4C];
    s32 w68;
    u8 pad6C[0x3E];
    s16 hAA;
    u8 padAC[0x0];
} Obj_00669538;
extern E_00669538 D_L39_0033ACA0[];
extern s32 D_L39_002412AC;
extern s32 D_L39_0024D070;
typedef struct { u8 pad0[0x128]; s32 f128; } G_00669538;
extern G_00669538 D_001A5E50;
extern s32 D_001E17A8_sda_00669538;
__asm__(".extern D_001E17A8_sda_00669538, 4");
extern void func_L39_00669B18(void);
extern void func_L39_006692B0(void);
extern void func_L39_00669478(s32);
extern void func_L39_00669B68(void *);
extern void func_003C1A90(void);
extern void func_003C26C8(void *);

void func_L39_00669538(void) {
        s32 i;
    Obj_00669538 *o;

    func_L39_00669B18();
    D_L39_0024D070 = 0;
    D_001E17A8_sda_00669538 = D_001A5E50.f128;
    func_L39_006692B0();
    if (D_L39_002412AC % 15 == 0) {
        func_L39_00669478(5);
    }
    for (i = 0; i < 50; i++) {
        o = D_L39_0033ACA0[i].obj;
        if (D_L39_0033ACA0[i].b31 == 1 && o != 0 && *(s32 *)((u8 *)o + 0x90) != 0 && o->w68 != 0) {
            if (D_L39_0033ACA0[i].b30 != 0 && D_L39_0033ACA0[i].f2C != 0) {
                D_L39_0033ACA0[i].f2C();
            }
            if (D_L39_0033ACA0[i].f28 != 0) {
                D_L39_0033ACA0[i].f28(D_L39_0033ACA0[i].obj);
            }
            o = D_L39_0033ACA0[i].obj;
            if (o != 0) {
                if (o->hAA == 0x109D) {
                    func_003C1A90();
                    func_003C26C8(D_L39_0033ACA0[i].obj);
                }
            }
            if (D_L39_0033ACA0[i].obj->x < 2.0f || D_L39_0033ACA0[i].obj->x > 1021.0f || D_L39_0033ACA0[i].obj->y < 2.0f || D_L39_0033ACA0[i].obj->y > 1021.0f || D_L39_0033ACA0[i].obj->z < 2.0f || D_L39_0033ACA0[i].obj->z > 1021.0f) {
                func_L39_00669B68(D_L39_0033ACA0[i].w0);
            }
        }
    }
    func_L39_00669B18();
}
/* localdecomp:end func_L39_00669538 */
