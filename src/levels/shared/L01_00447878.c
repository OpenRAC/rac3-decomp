#include "common.h"

/* localdecomp:start func_L01_00447878 */
#include "vu0.h"
extern f32 func_0038CED8(void *);

f32 func_L01_00447878(f32 *a, f32 *b, f32 *out, f32 d, f32 e) {
    vu0_v4 v;
    f32 t;

    vec_sub_ab(&v, b, a);
    t = func_0038CED8(&v) / d;
    if (out != 0) {
        *out = t;
    }
    if (t != 0.0f) {
        return -((a[2] - b[2]) + e * (t * t) * 0.5f) / t;
    }
    return 0.0f;
}
/* localdecomp:end func_L01_00447878 */

/* localdecomp:start func_L01_00447938 */
extern void func_003C97F0(void *, s32, s32);
extern void func_0038CE50(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_003824E0(f32, f32);
extern void func_L01_0040E408(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern f32 func_00382538(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0012FF10(void *, void *, f32);

s32 func_L01_00447938(f32 density, u8 *object, s32 limit, vu0_v4 *output, s32 mask)
{
    f32 volumes[20];
    u8 *shapes[20];
    vu0_v4 center, random, delta, point, jitter;
    u8 *shape;
    f32 total;
    s32 count, index, last, n, i, kind;
    f32 value;
    {
        u8 *shape = *(u8 **)(*(u8 **)(object + 0x24) + 0x10);
        if (shape == 0) return 0;
        if (*(s16 *)(shape + 2))
            func_003C97F0(object, *(s16 *)(shape + 2), 0);
        if (*(s32 *)(shape + 4) <= 0) return 0;
        shape += 16;
        total = 0.0f;
        count = 0;
        index = 0;
        {
            u8 *data = shape + 4;
            do {
                s32 kind;
                u32 flags = *(u32 *)(data - 4);
                u32 active;
                last = flags >> 31;
                kind = flags & 255;
                active = flags & 0x20000;
                if (!(((mask >> index) ^ 1) & 1) && active) {
                    shapes[count] = shape;
                    switch (kind) {
                    case 0: case 1: case 2: {
                        f32 radius;
                        if (kind < 2) {
                            center = *(vu0_v4 *)(shape + 16);
                            func_0038CE50(&center, &center, *(f32 *)(object + 0x2C) * (1.0f / 1024.0f));
                            radius = center.w;
                        } else {
                            center = *(vu0_v4 *)(0x70000000 + (*(s32 *)(data) << 4));
                            random = *(vu0_v4 *)(shape + 16);
                            vec_add_ab(&center, &center, &random);
                            func_0038CE20(&center, &center, *(f32 *)(object + 0x2C) * (1.0f / 1024.0f));
                            radius = *(f32 *)(object + 0x2C);
                            radius = *(f32 *)(data + 8) * radius * (1.0f / 1024.0f);
                        }
                        volumes[count] = radius * 4.188790321350098f * radius * radius;
                        break;
                    }
                    case 3: {
                        f32 radius, height;
                        center = *(vu0_v4 *)(shape + 16);
                        func_0038CE20(&center, &center, *(f32 *)(object + 0x2C));
                        radius = center.w * *(f32 *)(object + 0x2C) * (1.0f / 1024.0f);
                        height = *(f32 *)(data) * (*(f32 *)(object + 0x2C) * (1.0f / 1024.0f));
                        volumes[count] = radius * 4.187743186950684f * radius * radius + radius * 1.5707963705062866f * radius * height;
                        break;
                    }
                    case 4: {
                        f32 radius, height;
                        func_0012FF10(&center, (void *)(0x70000000 + (*(s16 *)(data) << 4)), *(f32 *)(object + 0x2C) * (1.0f / 1024.0f));
                        func_0012FF10(&random, (void *)(0x70000000 + (*(s16 *)(data + 2) << 4)), *(f32 *)(object + 0x2C) * (1.0f / 1024.0f));
                        vec_sub_ab(&delta, &center, &random);
                        radius = func_0038CEA8(&delta);
                        height = *(f32 *)(data + 8) * *(f32 *)(object + 0x2C) * (1.0f / 1024.0f);
                        volumes[count] = height * 1.5707963705062866f * height * radius;
                        break;
                    }
                    }
                    total += volumes[count++];
                }
                shape += 32;
                data += 32;
                index++;
            } while (!last);
        }
    }
    n = (s32)(density * total + 0.5f);
    if (limit < n) n = limit;
    for (i = 0; i < n; i++) {
        value = func_003824E0(0.0f, total);
        {
            s32 selected;
            for (selected = 0; selected < count; selected++) {
                if (value < volumes[selected]) break;
                value -= volumes[selected];
            }
            shape = shapes[selected];
        }
        kind = *shape;
        switch (kind) {
        case 0: case 1: case 2: {
            f32 radius, negative;
            if (kind < 2) {
                center = *(vu0_v4 *)(shape + 16);
                func_0038CE20(&center, &center, *(f32 *)(object + 0x2C));
                radius = center.w * *(f32 *)(object + 0x2C);
            } else {
                center = *(vu0_v4 *)(0x70000000 + (*(s32 *)(shape + 4) << 4));
                random = *(vu0_v4 *)(shape + 16);
                vec_add_ab(&center, &center, &random);
                func_0038CE20(&center, &center, *(f32 *)(object + 0x2C));
                radius = *(f32 *)(shape + 12) * *(f32 *)(object + 0x2C);
            }
            radius = radius * (1.0f / 1024.0f);
            negative = -radius;
            func_L01_0040E408(&center, &center, 1024.0f);
            for (;;) {
                random.x = func_003824E0(negative, radius);
                random.y = func_003824E0(negative, radius);
                random.z = func_003824E0(negative, radius);
                if (func_0038CEA8(&random) <= radius) {
                    vec_add_ab(&random, &random, &center);
                    func_0038D000(&random, &random, object + 0xC0);
                    vec_add_ba(&output[i], &random, object + 0x10);
                    break;
                }
            }
            break;
        }
        case 3: {
            f32 radius, height, a, b, angle;
            center = *(vu0_v4 *)(shape + 16);
            func_0038CE20(&center, &center, *(f32 *)(object + 0x2C));
            radius = center.w * *(f32 *)(object + 0x2C);
            height = *(f32 *)(shape + 4) * *(f32 *)(object + 0x2C);
            func_L01_0040E408(&center, &center, 1024.0f);
            radius *= 1.0f / 1024.0f;
            height *= 1.0f / 1024.0f;
            a = sqrt_asm(func_003824E0(0.0f, radius * radius));
            b = func_003824E0(0.0f, height);
            angle = func_00382538();
            random.x = func_0038D098(angle) * a;
            random.y = func_0038D0B0(angle) * a;
            random.z = b;
            vec_add_ba(&random, &random, object + 0x10);
            vec_add_ab(&output[i], &center, &random);
            break;
        }
        case 4: {
            f32 radius, negative;
            u8 *data = shape + 4;
            func_0012FF10(&center, (void *)(0x70000000 + (*(s16 *)(data) << 4)), *(f32 *)(object + 0x2C));
            func_0012FF10(&random, (void *)(0x70000000 + (*(s16 *)(data + 2) << 4)), *(f32 *)(object + 0x2C));
            vec_sub_ab(&delta, &random, &center);
            func_0038CE20(&delta, &delta, func_003824E0(0.0f, 1.0f));
            vec_add_ab(&point, &delta, &center);
            func_L01_0040E408(&point, &point, 1024.0f);
            radius = *(f32 *)(shape + 12) * *(f32 *)(object + 0x2C);
            radius *= 1.0f / 1024.0f;
            negative = -radius;
            for (;;) {
                jitter.x = func_003824E0(negative, radius);
                jitter.y = func_003824E0(negative, radius);
                jitter.z = func_003824E0(negative, radius);
                if (func_0038CEA8(&jitter) <= radius) {
                    vec_add_ab(&jitter, &jitter, &point);
                    func_0038D000(&jitter, &jitter, object + 0xC0);
                    vec_add_ba(&output[i], &jitter, object + 0x10);
                    break;
                }
            }
            break;
        }
        }
    }
    return n;
}
/* localdecomp:end func_L01_00447938 */

LINKER_REMNANT("asm/levels", func_L01_00448060);

/* localdecomp:start func_L01_00448070 */
int func_L01_00448070(int a, int b, float t)
{
    return a + (int)((b - a) * t);
}
/* localdecomp:end func_L01_00448070 */
