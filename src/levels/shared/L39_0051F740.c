#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u128_t v0, v1, v2;
    u128_t matrix[3];
} Local_51FC18;

typedef struct __attribute__((packed)) { s32 values[2]; } Pair;

/* localdecomp:start func_L39_0051F740 */
#include "vu0.h"
typedef struct {
    u8 pad[0x10];
    f32 f10;
    s32 i14;
    f32 f18;
    s32 i1C;
    s32 i20;
    s32 i24;
    s32 i28;
    s32 i2C;
    u8 *p30;
} Data_0051F740;
typedef struct {
    vu0_v4 v;
    s32 x10, x14;
    u8 b18;
    u8 b19;
    u16 h1A;
    s32 x1C;
    s32 w20;
    s32 x24;
    s32 w28;
    s32 x2C;
} Dmg_0051F740;
typedef struct {
    u8 pad[0x20];
    f32 f20;
    s32 x24;
    s32 w28;
    s32 w2C;
    u8 pad2[0x460 - 0x30];
} Slot_0051F740;
typedef struct {
    u8 pad[0x21];
    s8 x21;
    u8 pad22[0x34 - 0x22];
    f32 f34;
    u8 pad2[0x80 - 0x38];
} Tab_0051F740;
extern Slot_0051F740 D_L39_0024DE80[];
extern u8 *D_L39_0024CE20[8] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024CE20, 32");
extern u8 *D_L39_002637C0[];
extern Tab_0051F740 D_L39_0049C890[];
extern s32 func_L01_00457458(s32, s32);
extern void func_003C2880(char *);
extern s32 func_L01_004572B0(void *, s32, void *);
extern char *func_L01_00457480(s32, s32);
extern void func_L39_0051FD90(void *, void *);
extern s32 func_L39_005BE900(void *, s32, f32);
extern void func_L39_005FFDF8(s32);
extern s32 func_003D4D00(void *, s32, void *, s32, f32);
extern void func_L39_005FFE78(void);
extern u8 *func_00382348(void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L39_00648AE0(u8 *, s32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L01_00446978(void *, void *);
extern s32 func_0038CAD0(void *);
extern void func_L01_00404A10(void *, void *);
extern void func_L39_00520350(char *);

void func_L39_0051F740(char *obj)
{
    vu0_v4 pos;
    vu0_v4 t;
    Dmg_0051F740 dmg;
    u8 local[16];
    Data_0051F740 *data = *(Data_0051F740 **)(obj + 0x68);
    f32 f;
    f32 k;
    f32 g;
    s32 n;
    s32 id;
    s32 i;
    char *at;
    u8 *p;
    Tab_0051F740 *e;

    if (*(u8 *)(obj + 0x20) != 0 &&
        func_L01_00457458(*(s16 *)(obj + 0xAA), data->i28) == 0) {
        func_003C2880(obj);
        return;
    }
    switch (*(u8 *)(obj + 0x20)) {
    case 0:
        *(u8 *)(obj + 0x20) = 1;
        data->f10 = 0.0f;
        data->i14 = 0x11;
        data->f18 = 0.80000007f;
        data->i1C = 0x7F;
        data->i24 = 0x6F;
        data->i28 = func_L01_004572B0(obj, 0, local);
        func_L01_00457480(*(s16 *)(obj + 0xAA), data->i28);
        pos = *(vu0_v4 *)(obj + 0x10);
        pos.z += 1.0f;
        func_L39_0051FD90(obj, obj + 0x10);
        if (data->p30 != 0) {
            t = pos;
            t.w = 2.0f;
            if (func_L39_005BE900(&t, 0, 100.0f) != -1) {
                (D_L39_0024DE80 + (data->p30)[0x24C9])->f20 = 0.45f;
                (D_L39_0024DE80 + (data->p30)[0x24C9])->w28 = 0x21;
                (D_L39_0024DE80 + (data->p30)[0x24C9])->w2C = 0;
            }
        }
    case 1:
        data->i24 -= 5;
        if (data->i24 < 0)
            data->i24 = 0;
        at = obj + 0x10;
        g = (f32)data->i14 / 17.0f;
        data->f10 += data->f18;
        k = (1.0f - g) * 6.0f + 0.001f;
        id = *(s32 *)(data->p30 + 0x2544);
        p = D_L39_0024CE20[id];
        id = p != 0 ? *(s32 *)(p + 0x2548) : -1;
        func_L39_005FFDF8(id);
        n = func_003D4D00(at, 0, obj, 0, k);
        func_L39_005FFE78();
        for (i = 0; i < n; i++) {
            Tab_0051F740 *tab = D_L39_0049C890;
            Tab_0051F740 *def = &D_L39_0049C890[5];

            if (func_00382348(D_L39_002637C0[i]) == 0 && (*(u16 *)(D_L39_002637C0[i] + 0x34) & 0x4000) == 0)
                continue;
            if (data->p30 == 0 || D_L39_002637C0[i] == *(u8 **)(data->p30 + 0x2524)) {
                if (*(s16 *)(D_L39_002637C0[i] + 0xAA) != 0x1068)
                    continue;
            }
            if (*(s16 *)(D_L39_002637C0[i] + 0xAA) == 0xA5A)
                continue;
            vec_sub_ba(&t, D_L39_002637C0[i] + 0x10, obj + 0x10);
            func_0038CF68(&t, &t, 1.0f);
            func_0038CF68(&dmg, &dmg, 1.0f);
            if (func_L39_00648AE0(data->p30, 5) != 0)
                e = &D_L39_0049C890[def->x21];
            else
                e = &tab[5];
            func_L01_00446760(&dmg, obj, 0x1030001, &t, e->f34);
            dmg.v = t;
            dmg.w20 = 1;
            dmg.v.w = 5627.925f;
            dmg.b18 = 5;
            dmg.b19 = 3;
            dmg.h1A = *(u16 *)(D_L39_002637C0[i] + 0xAA);
            dmg.w28 = data->i2C;
            func_L01_00446978(D_L39_002637C0[i], &dmg);
        }
        if (func_0038CAD0(&data->i14) != 0) {
            *(u8 *)(obj + 0x20) = 2;
            data->i14 = 0x21;
        }
        break;
    case 2:
        data->f10 += data->f18;
        f = (f32)data->i14 / 40.0f;
        if (func_0038CAD0(&data->i14) != 0) {
            if (data->i1C != 0) {
                data->i1C -= 1;
            } else {
                data->i1C = 0;
                *(u8 *)(obj + 0x20) = 6;
            }
        } else {
            data->i1C = (s32)(f * 127.0f);
        }
        break;
    case 6:
        data->f10 += data->f18;
        func_003C2880(obj);
        return;
    }
    func_L01_00404A10(func_L39_00520350, obj);
}
/* localdecomp:end func_L39_0051F740 */
