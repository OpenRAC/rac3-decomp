#include "common.h"

typedef struct {
    u8 *obj;
    s32 col;
    s32 pad8;
    f32 t;
    u8 pad10[16];
} Ent_003153D8;
typedef struct {
    f32 v[4][4];
    u8 pad40[0x10];
    f32 w[4][2];
    unsigned long d70;
    u8 pad78[8];
    unsigned long d80;
} Obj317488;
typedef struct {
    u8 pad0[56];
    s32 w56;
    s32 w60;
} S_00142660;
typedef struct {
    u8 pad[8];
    s32 x8;
} S_142660;
typedef struct { u8 pad[20]; s32 id; u8 pad2[8]; } E_31ABE0;
typedef int u128_t __attribute__((mode(TI)));

typedef struct { u8 pad[0x1C]; s32 active; u8 pad20[0x10]; } E_L01_00272540_00318408;
typedef struct { u8 pad[0x44]; s32 active; u8 pad48[8]; } E_L01_00272780_00318408;
typedef struct { u8 pad0[0x25C0]; s32 x25C0; u8 pad25C4[0x2850 - 0x25C4]; s32 x2850; } G_00318408;




/* localdecomp:start func_L01_00318428 */
#include "vu0.h"
extern G_00318408 D_001A4BE0;
extern E_L01_00272540_00318408 D_L01_002725C0[];
void func_L01_00318428(s32 owner) {
    extern f32 func_L01_00440978(void);
    extern f32 func_L01_00440918(f32, f32);
    extern f32 func_L01_004408C0(f32, f32);
    extern void func_L01_004C41E8(void *, void *);
    extern void func_L01_0040BF20(f32 *, f32 *, f32 *);
    extern void func_L01_0040C0F0(f32 *, f32 *, f32);
    vu0_v4 offset, position, end;
    E_L01_00272540_00318408 *p;
    p = D_L01_002725C0;
    do {
        if (p->active == 0) {
            p->active = owner;
            *(f32 *)((u8 *)p + 0x10) = func_L01_00440978();
            *(f32 *)((u8 *)p + 0x14) = func_L01_00440918(1200.0f, 1400.0f) * 0.017453292f * 0.0166666675f;
            *(s32 *)((u8 *)p + 0x18) = 37;
            *(f32 *)((u8 *)p + 0x20) = func_L01_004408C0(0.3f, 0.4f);
            func_L01_004C41E8((void *)(D_001A4BE0.x25C0 + 0x10), &offset);
            *(vu0_q *)&position = *(vu0_q *)(D_001A4BE0.x25C0 + 0x10);
            vec_add_ab(&end, &position, &offset);
            func_L01_0040BF20((f32 *)&position, (f32 *)&position, (f32 *)&end);
            func_L01_0040C0F0((f32 *)p, (f32 *)&position, *(f32 *)((u8 *)p + 0x20));
            break;
        }
        p++;
    } while ((s32)p < (s32)(D_L01_002725C0 + 12));
}
/* localdecomp:end func_L01_00318428 */
