#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u128_t v0, v1, v2;
    u128_t matrix[3];
} Local_51FC18;

typedef struct __attribute__((packed)) { s32 values[2]; } Pair;

/* declared by functions of L39_0051F740.c, which this file was cut from */
extern void func_0038CF68(void *, void *, f32);

/* localdecomp:start func_L39_00521FE0 */
extern s32 func_0038CB00(void *);
extern void func_L39_00521DE8(void *);
extern f32 func_L39_005B44C8(void);
extern f32 func_L39_005B4410(f32, f32);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);

void func_L39_00521FE0(char *obj)
{
    char *data;

    if (obj == 0)
        return;
    if (*(s16 *)(obj + 0xAA) != 0x1094)
        return;
    if (*(u8 *)(obj + 0x20) == 0xFE)
        return;
    if (*(u8 *)(obj + 0x20) == 0xFD)
        return;
    data = *(char **)(obj + 0x68);
    if (data == 0)
        return;
    if (func_0038CB00(data + 0x50) != 0)
        return;
    func_L39_00521DE8(obj);
    func_L39_00521DE8(obj);
    if (*(s16 *)(data + 0x64) != 0) {
        func_003D9508(data, 0x31, 0x3F204090, 1, 0.6f, 0.0f, func_L39_005B44C8());
        func_003D9508(data, 0x31, 0x3F204090, 1, 0.6f, 0.0f, func_L39_005B44C8());
        func_003D9508(data, 0xB, 0x3F204090, 1, 0.6f, 0.08f, 0.0f);
        func_003D9508(data, 0x41, 0x3F909090, 1, 0.75f, 0.0f, func_L39_005B4410(30.0f, 60.0f) * 0.017453292f);
    } else {
        char *p = data + 0x10;
        func_003D9508(p, 0x31, 0x3F204090, 1, 0.6f, 0.0f, func_L39_005B44C8());
        func_003D9508(p, 0x31, 0x3F204090, 1, 0.6f, 0.0f, func_L39_005B44C8());
        func_003D9508(p, 0xB, 0x3F204090, 1, 0.6f, 0.08f, 0.0f);
        func_003D9508(p, 0x41, 0x3F909090, 1, 0.75f, 0.0f, func_L39_005B4410(30.0f, 60.0f) * 0.017453292f);
    }
}
/* localdecomp:end func_L39_00521FE0 */

LINKER_REMNANT("asm/levels", func_L39_00522248);

/* localdecomp:start func_L39_00522260 */
typedef struct { f32 x, y, z; } V3_00522248;
typedef struct { f32 x, y, z, w; } V4_00522248 __attribute__((aligned(16)));

void func_L39_00522260(u8 *obj, u8 *msg) {
    u8 *data;
    u8 *t;
    V4_00522248 d;

    if (msg[3] == 8) {
        data = *(u8 **)(obj + 0x68);
        if (*(s16 *)(data + 0x64) != 0) {
            {
                V3_00522248 *a = (V3_00522248 *)(msg + 0xC);
                V3_00522248 *b = (V3_00522248 *)(data + 0x10);
                a->x = b->x;
                a->y = b->y;
                a->z = b->z;
            }
        } else {
            {
                V3_00522248 *a = (V3_00522248 *)(msg + 0xC);
                V3_00522248 *b = (V3_00522248 *)data;
                a->x = b->x;
                a->y = b->y;
                a->z = b->z;
            }
        }
        {
            V3_00522248 *a = (V3_00522248 *)(msg + 0x18);
            V3_00522248 *b = (V3_00522248 *)(data + 0x20);
            a->x = b->x;
            a->y = b->y;
            a->z = b->z;
        }
        *(s32 *)(msg + 8) = *(s32 *)(data + 0x5C);
        t = *(u8 **)(data + 0x70);
        if (t != 0) {
            __asm__ __volatile__(
                "lqc2 $vf1, 0x40(%1)\n"
                "lqc2 $vf2, 0x10(%2)\n"
                "vsub.xyz $vf1, $vf1, $vf2\n"
                "sqc2 $vf1, 0(%0)\n"
                : : "r"(&d), "r"(data), "r"(t) : "memory");
            {
                V3_00522248 *a = (V3_00522248 *)(msg + 0xC);
                V3_00522248 *b = (V3_00522248 *)&d;
                a->x = b->x;
                a->y = b->y;
                a->z = b->z;
            }
        }
    }
}
/* localdecomp:end func_L39_00522260 */
