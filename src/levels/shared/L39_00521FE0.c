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

/* localdecomp:start func_L39_00523948 */
extern s32 *D_001D5A10_sda;
extern s32 func_0038DC20(f32 *, f32);
extern void func_003A9440(s32, unsigned long);
extern void func_L39_00523D38(void *, s32, s32, f32);
extern void func_L39_00523B68(void *, void *, s32, f32);
extern void func_L39_005247C0(void *);

void func_L39_00523948(char *obj)
{
    char *p;
    u128_t local;
    u8 kind;

    if (obj == 0)
        return;
    if (*(s16 *)(obj + 0xAA) != 0x10A4)
        return;
    kind = *(u8 *)(obj + 0x20);
    if (kind == 0xFE)
        return;
    if (kind == 0xFD)
        return;
    p = *(char **)(obj + 0x68);
    if (p == 0)
        return;
    if (*D_001D5A10_sda >= 2) {
        local = *(u128_t *)(obj + 0x10);
        *(f32 *)((char *)&local + 12) = 25.0f;
        if (func_0038DC20((f32 *)&local, 96.0f) < 0)
            return;
    }
    func_003A9440(0x47, 0x53001);
    func_L39_00523D38(obj, 0x7F7F7F7F, 0x4B, 0.05f);
    if (*(f32 *)(p + 0x40) != 0.0f) {
        func_L39_00523B68(obj, p + 0x10, 0x7F10307F, 0.25f);
        func_L39_00523B68(obj, p + 0x10, 0x3F08183F, 0.5f);
    }
    func_L39_005247C0(obj);
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L39_00523948 */
