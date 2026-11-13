#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u128_t v0, v1, v2;
    u128_t matrix[3];
} Local_51FC18;

typedef struct __attribute__((packed)) { s32 values[2]; } Pair;

INCLUDE_ASM("asm/levels", func_L39_0051F740);

/* localdecomp:start func_L39_0051FC18 */
extern u8 *func_003C24B0(s32, s32);
extern void func_0038D308(void *, void *);
extern void func_0038D278(void *);
extern void func_L39_005BC330(void *, void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D0B0(f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038D098(f32);
extern void func_0038D810(void *, void *);
extern void func_0038D5F0(void *, void *, void *);

u8 *func_L39_0051FC18(u128_t *pos, u128_t *dir, s32 a2, u8 *a3)
{
    Local_51FC18 local;
    u8 *o = func_003C24B0(0x1091, 0x80);
    u8 *data = *(u8 **)(o + 0x68);
    u8 *axis;
    f32 half;
    s16 header;

    if (o != 0) {
        header = 0xFF;
        *(u16 *)(o + 0x34) |= 0x100;
        o[0x20] = 0;
        *(s16 *)(o + 0x32) = header;
        o[0x30] = header;
        *(u128_t *)(o + 0x10) = *pos;
        *(u128_t *)data = *dir;
        *(s32 *)(data + 0x2C) = a2;
        *(u8 **)(data + 0x30) = a3;
        if (a3 != 0)
            func_0038D308((o + 0xC0), *(u8 **)(a3 + 0x2524) + 0xF0);
        else
            func_0038D278((o + 0xC0));
        func_L39_005BC330(o + 0x10, &local.v2, 1);
        axis = o + 0xE0;
        func_0038CF68(&local.v2, &local.v2, 1.0f);
        func_0038CE90(&local.v1, axis, &local.v2);
        half = func_0038CE68(axis, &local.v2) * 0.5f;
        func_0038CE20(&local.v0, &local.v1, func_0038D0B0(half));
        *(f32 *)((u8 *)&local.v0 + 12) = func_0038D098(half);
        func_0038D810(&local.v0, local.matrix);
        func_0038D5F0((o + 0xC0), local.matrix, (o + 0xC0));
    }
    return o;
}
/* localdecomp:end func_L39_0051FC18 */

INCLUDE_ASM("asm/levels", func_L39_0051FD90);

/* localdecomp:start func_L39_00520350 */
extern s32 func_L01_00457458(s32, s32);
extern void func_003C2880(char *);
extern s32 func_0038DC20(char *, f32);
extern void func_L39_005203E0(char *);
extern void func_L39_00520630(char *);

void func_L39_00520350(char *obj)
{
    char local[16];
    s32 r;

    if (*(s32 *)(obj + 0x68) == 0)
        return;
    r = func_L01_00457458(*(s16 *)(obj + 0xAA), *(s32 *)(*(s32 *)(obj + 0x68) + 0x28));
    if (r == 0) {
        func_003C2880(obj);
        return;
    }
    *(u128_t *)local = *(u128_t *)(obj + 0x10);
    *(f32 *)(local + 0xC) = 2.0f;
    r = func_0038DC20(local, 100.0f);
    if (r == -1)
        return;
    func_L39_005203E0(obj);
    func_L39_00520630(obj);
}
/* localdecomp:end func_L39_00520350 */

INCLUDE_ASM("asm/levels", func_L39_005203E0);

INCLUDE_ASM("asm/levels", func_L39_00520630);

INCLUDE_ASM("asm/levels", func_L39_00520870);

INCLUDE_ASM("asm/levels", func_L39_005210A0);

INCLUDE_ASM("asm/levels", func_L39_00521BC0);

INCLUDE_ASM("asm/levels", func_L39_00521DE8);

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

INCLUDE_ASM("asm/levels", func_L39_00522248);

INCLUDE_ASM("asm/levels", func_L39_00522328);

/* localdecomp:start func_L39_00522EE8 */
extern s32 func_0019D510();
extern void func_L39_005237D0(char *object, char *entry);
extern void func_L01_00466F50(char *a, char *b, s32 c, f32 d, f32 e);

void func_L39_00522EE8(char *object)
{
    char *state = *(char **)(object + 0x68);
    int first = *(int *)(state + 0x38);
    int last = *(int *)(state + 0x34);
    int end;
    int index;
    int random;

    end = first + 2;
    index = end - last;
    if (index <= -1)
        index += 0x23;

    random = func_0019D510();
    if (random % 7 == 0)
        func_L39_005237D0(object, *(char **)(state + 0x5C) + (index << 6));

    random = func_0019D510();
    if (random % 0x16 == 0) {
        char *entry = *(char **)(state + 0x5C) + (index << 6);
        func_L01_00466F50(entry, entry + 0x10, 0, -1.0f, 0.0f);
    }
}
/* localdecomp:end func_L39_00522EE8 */

INCLUDE_ASM("asm/levels", func_L39_00522FA8);

/* localdecomp:start func_L39_005236F0 */
extern void func_L01_004C8668(s32);
extern s32 func_L39_005FF538(void *, void *, f32, f32, f32);
void func_L39_005236F0(void *obj, u128_t *p1, u128_t *p2, s32 arg) {
    u8 *st = *(u8 **)((u8 *)obj + 0x68);
    u8 *e = *(u8 **)(st + 0x5C) + (*(s32 *)(st + 0x24) << 6);
    *(u128_t *)e = *p1;
    *(u128_t *)(e + 0x10) = *p2;
    if (*(s32 *)(e + 0x38) >= 0) {
        func_L01_004C8668(*(s32 *)(e + 0x38));
    }
    *(s32 *)(e + 0x38) = func_L39_005FF538(obj, e, 1.0f, 1.0f, 1.0f);
    *(s32 *)(e + 0x30) = arg;
    *(s32 *)(e + 0x3C) = 1;
    *(s32 *)(e + 0x34) = 0;
    *(s32 *)(st + 0x38) = *(s32 *)(st + 0x24);
    *(s32 *)(st + 0x24) = *(s32 *)(st + 0x24) + 1;
    if (*(s32 *)(st + 0x24) >= 0x23) {
        *(s32 *)(st + 0x30) = 1;
        *(s32 *)(st + 0x24) = 0;
    } else if (*(s32 *)(st + 0x30) != 1) {
        *(s32 *)(st + 0x34) = *(s32 *)(st + 0x34) + 1;
    }
}
/* localdecomp:end func_L39_005236F0 */

INCLUDE_ASM("asm/levels", func_L39_005237D0);

/* localdecomp:start func_L39_00523860 */
extern Pair D_L39_0024A9E0[];
extern s32 D_L39_0024A9EC;
__asm__(".extern D_L39_0024A9EC, 4");
extern void func_0038CF68(void *, void *, f32);
extern f32 func_L39_005B4410(f32, f32);
extern void *func_L39_005D3B70(void *, void *, s32, f32);

void *func_L39_00523860(char *self, void *position, u128_t *src)
{
    struct { u128_t local; Pair choices; } temp;
    char *state = *(char **)(self + 0x68);
    f32 size;
    void *r;
    s32 *selected;

    temp.local = *src;
    func_0038CF68(&temp.local, &temp.local, 0.05f);
    temp.choices = D_L39_0024A9E0[0];
    selected = temp.choices.values;
    size = func_L39_005B4410(0.05f, 0.1f);
    selected += D_L39_0024A9EC % 2;
    r = func_L39_005D3B70(position, &temp.local, *selected, size * *(f32 *)(state + 0x40) * 0.1f);
    D_L39_0024A9EC += 1;
    return r;
}
/* localdecomp:end func_L39_00523860 */

INCLUDE_ASM("asm/levels", func_L39_00523948);
