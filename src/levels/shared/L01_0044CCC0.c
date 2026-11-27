#include "common.h"

LINKER_REMNANT("asm/levels", func_L01_0044CCC0);

/* localdecomp:start func_L01_0044CCC8 */
extern u8 D_001D5530[] __attribute__((section(".sdata")));
extern s32 D_00143050[];

void func_L01_0044CCC8(s32 id) {
    s32 i;
    s32 n;

    if (D_001D5530[id] == 0) {
        s32 t = 0;
        do {
            t++;
            if (t >= 60) {
                break;
            }
        } while (1);
        D_001D5530[id] = 1;
        if (id < 30 && id != 24) {
            n = 0;
            for (i = 0; i < 60; i++) {
                if (D_00143050[i] != 0) {
                    n++;
                }
            }
            D_00143050[n] = id;
        }
    }
}
/* localdecomp:end func_L01_0044CCC8 */

/* localdecomp:start func_L01_0044CD60 */
typedef struct {
    u8 pad0[8];
    s32 w8;
    u8 padC[4];
    s32 w10;
    u8 pad14[0xF0 - 0x14];
} S_449AE8;

extern u8 D_001425C0[];
extern S_449AE8 D_L01_002C5600[];
extern s16 D_001CCFD4[];
extern s32 D_001A71D8[];
extern s32 D_001A71DC[];
extern s32 D_001A71E0[];
extern s32 D_001A71E4[];
extern s32 func_0039AC08(s32);
extern void func_0039AA38(s32);
extern void func_L01_005078C0(s32);

s32 func_L01_0044CD60(s32 id) {
    s32 ret;
    s32 st;
    u8 *ip;
    S_449AE8 *tbl;
    S_449AE8 *e;

    ip = D_001425C0 + id;
    tbl = D_L01_002C5600;
    ret = 0;
    e = tbl + *ip;
    st = e->w8;
    if (st == 0) {
        if (func_0039AC08(e->w10) != 0 || D_001CCFD4[0] == 0) {
            D_001A71D8[0] = id;
            func_L01_005078C0(id);
            if (func_0039AC08((tbl + *ip)->w10) == 0) {
                func_0039AA38((tbl + *ip)->w10);
            }
            ret = 1;
        }
    } else if (st == 3) {
        D_001A71E4[0] = id;
        ret = 1;
    } else if (st == 2) {
        D_001A71E0[0] = id;
        ret = 1;
    } else if (st == 1) {
        D_001A71DC[0] = id;
        ret = 1;
    }
    return ret;
}
/* localdecomp:end func_L01_0044CD60 */

/* localdecomp:start func_L01_0044CE88 */
#include "structs/moby.h"

typedef struct {
    u8 pad0[0x1200];
    struct Moby *hand_moby;        /* 0x1200 */
    u8 pad1204[0x1228 - 0x1204];
    s32 held_item;                 /* 0x1228 */
} Hero_0044CE88;

typedef struct {
    u8 pad0;
    u8 b1;
    u8 pad2[0x10 - 2];
    s32 oclass;
    u8 pad14[0xF0 - 0x14];
} Item_0044CE88;

extern Hero_0044CE88 D_001A4BE0;
extern Item_0044CE88 D_L01_002C5600_0044CE88[];

s32 func_L01_0044CE88(struct Moby *m) {
    struct Moby *hand;
    s32 i;
    s32 cls;

    if (m == 0) {
        return 0xFF;
    }
    if (D_001A4BE0.held_item == 0x87 && m->oclass == 0x1893) {
        return 0x87;
    }
    if (D_001A4BE0.held_item == 0x57 && m->oclass == 0x1893) {
        return 0x57;
    }
    if (D_001A4BE0.held_item == 0x77 && D_L01_002C5600_0044CE88[D_001425C0[0x77]].b1 >= 4 && m->oclass == 0x1855) {
        return 0x77;
    }
    if (D_001A4BE0.held_item == 0x11 && (m->oclass == 0xC59 || m->oclass == 0x5C9)) {
        return 0x11;
    }
    if (D_001A4BE0.held_item == 0x7F && m->oclass == 0x47) {
        return 0x7F;
    }
    if (D_001A4BE0.held_item == 0x47 && m->oclass == 0x1195) {
        return 0x47;
    }
    switch (m->oclass) {
    case 0x1195:
        return 0x16;
    case 0x1869:
    case 0x186D:
        return 0x67;
    case 0x1870:
    case 0x189B:
    case 0x1C59:
        return 0x8F;
    case 0x1871:
    case 0x1873:
        return 0x97;
    case 0x186A:
    case 0x186B:
        return 0x5F;
    case 0x1866:
    case 0x1867:
        return 0x4F;
    case 0xA65:
    case 0xA66:
    case 0xA82:
    case 0xC5A:
    case 0x1366:
        return 0x15;
    case 0xE64:
    case 0xECE:
        return 0x13;
    case 0x1864:
    case 0x1887:
    case 0x1894:
        return 0x3F;
    case 0x9A9:
    case 0xA9B:
        return 0x10;
    case 0x185B:
    case 0x1872:
    case 0x1892:
        return 0x87;
    case 0x1852:
    case 0x1853:
    case 0x1854:
    case 0x1855:
    case 0x188F:
    case 0x1893:
    case 0x1ADA:
    case 0x1AEC:
        return 0x57;
    case 0x1858:
    case 0x185A:
    case 0x1865:
    case 0x1885:
    case 0x1888:
    case 0x1898:
        return 0x77;
    case 0x5C9:
    case 0xB2E:
    case 0xC59:
        return 0x11;
    case 0x1843:
    case 0x1890:
    case 0x1CB8:
        return 0x7F;
    }
    hand = D_001A4BE0.hand_moby;
    if (m == hand) {
        return D_001A4BE0.held_item;
    }
    if (m->parent != 0 && m->parent == hand) {
        return D_001A4BE0.held_item;
    }
    cls = m->oclass;
    for (i = 0; i < 156; i++) {
        Item_0044CE88 *e = &D_L01_002C5600_0044CE88[D_001425C0[i]];
        if (cls == e->oclass) {
            return i;
        }
        if (m->parent != 0 && m->parent->oclass == e->oclass) {
            return i;
        }
    }
    return 0xFF;
}
/* localdecomp:end func_L01_0044CE88 */

/* localdecomp:start func_L01_0044D360 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_44D360;
typedef struct { u8 p0[0x18]; f32 f18; } Path_44D360;
typedef struct {
    u8 pad0[0x32];
    u8 x32;
    u8 x33;
    u8 pad34[0x3C - 0x34];
    s32 x3C;
    u8 pad40[0x5A - 0x40];
    u8 x5A;
} Stats_44D360;

extern s32 func_00382468(s32);
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_L01_004461B8(f32 *, f32 *, f32, f32, f32);
extern void func_L01_00477668(s32, void *, void *, void *);
extern void func_L01_002F8F20(void *, void *, void *, s32, s32, s32);
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 4");
extern s32 D_L01_001D6714;
extern u8 D_L01_001DFE80[] __attribute__((section(".sdata")));
extern s32 D_001A91E8[];
extern s32 D_001A9280[];
extern Stats_44D360 D_00142660;
extern Path_44D360 *D_L01_0021F6C0[];
extern u8 D_L01_00000258[];

/* Splits a bolt value into pickups (1 to 30000) and throws them out of the object, scaling the value by
   how fast the level is played (PAL). As rac2's moby_spawn_bolt_pickups_pal (src/pal/game/002AE6D8-g8.c). */
void func_L01_0044D360(u8 *object, s32 low, s32 high, s32 flags, s32 surface, s32 maximum, f32 height) {
    V4_44D360 offset;
    V4_44D360 position;
    V4_44D360 velocity;
    V4_44D360 half;
    V4_44D360 end;
    V4_44D360 hit;
    V4_44D360 correction;
    f32 t0, t1;
    s32 ones, fives, twenties, fifties, hundreds, fivehundreds, thousands, threethousands, tenthousands, thirtythousands;
    s32 value, remaining, enabled, q;
    f32 angle, x, y, duration;

    qzero(&offset);
    ones = 0; fives = 0; twenties = 0; fifties = 0; hundreds = 0; fivehundreds = 0; thousands = 0;
    threethousands = 0; tenthousands = 0; thirtythousands = 0;
    if (!(flags & 32) && object[0xB0] != 255 && (u32)(*(u16 *)(object + 0xAA) - 500) >= 41) {
        u32 index = object[0xB0];
        u8 *table = D_L01_001DFE80;
        D_L01_001D6714 = table[index] >> 7;
    }
    {
        s32 allowed = ((flags >> 5) ^ 1) & 1;
        enabled = 0;
        if (D_L01_001D6714) enabled = allowed;
    }
    if (!flags || (!low && !high)) return;
    if (low <= 0) low = 1;
    value = func_00382468(high - low + 1) + low;
    if (value < 500 && enabled && D_001A91E8[D_001D545C]) {
        s32 rate = D_001A9280[D_001D545C] * 3000 / D_001A91E8[D_001D545C];
        if (D_00142660.x32 || D_00142660.x33) rate /= 2;
#define limit ((s32)D_L01_00000258)
        if (rate < limit / 2) {
            if (rate <= limit * 3 / 10) {
                value *= 5;
            } else {
                value = value * (limit * 19 / 30 - rate) / (limit / 15);
            }
            if (D_00142660.x33) {
                if (value > limit * 10 / 3) value = limit * 10 / 3;
            } else if (value > limit * 5 / 3) value = limit * 5 / 3;
        } else if (limit < rate) {
            if (limit * 7 / 6 < rate) {
                value /= 10;
            } else {
                value = value * (limit * 6 / 5 - rate) / (limit * 4 / 15);
            }
            if (value <= 0) value = 1;
        }
#undef limit
    }
    remaining = value;
    if (flags & 8) {
        s32 count = maximum;
#define TAKE(n, denom) q = remaining / denom; n = q; if (n > count) n = count; \
        count -= n; remaining -= n * denom
        TAKE(thirtythousands, 30000);
        if (count > 0) { TAKE(tenthousands, 10000);
        if (count > 0) { TAKE(threethousands, 3000);
        if (count > 0) { TAKE(thousands, 1000);
        if (count > 0) { TAKE(fivehundreds, 500);
        if (count > 0) { TAKE(hundreds, 100);
        if (count > 0) { TAKE(fifties, 50);
        if (count > 0) { TAKE(twenties, 20);
        if (count > 0) { TAKE(fives, 5);
        if (count > 0) { ones = remaining; if (remaining > count) ones = count; }
        }}}}}}}}
#undef TAKE
        remaining /= D_00142660.x5A + 1;
        D_00142660.x3C += remaining;
    } else {
#define SPLIT(n, denom) if (remaining >= denom) { q = remaining / denom; n = q; remaining -= n * denom; }
        SPLIT(thirtythousands, 30000); SPLIT(tenthousands, 10000); SPLIT(threethousands, 3000);
        SPLIT(thousands, 1000); SPLIT(fivehundreds, 500); SPLIT(hundreds, 100);
        SPLIT(fifties, 50); SPLIT(twenties, 20); SPLIT(fives, 5);
#undef SPLIT
        ones = remaining;
        if (thirtythousands < 0 || tenthousands < 0 || threethousands < 0 || thousands < 0 || fivehundreds < 0 ||
            hundreds < 0 || fifties < 0 || twenties < 0 || fives < 0 || ones < 0) {
            thirtythousands = thirtythousands < 0 ? 0 : thirtythousands; tenthousands = tenthousands < 0 ? 0 : tenthousands;
            threethousands = threethousands < 0 ? 0 : threethousands; thousands = thousands < 0 ? 0 : thousands;
            fivehundreds = fivehundreds < 0 ? 0 : fivehundreds; hundreds = hundreds < 0 ? 0 : hundreds;
            fifties = fifties < 0 ? 0 : fifties; twenties = twenties < 0 ? 0 : twenties;
            fives = fives < 0 ? 0 : fives; ones = ones < 0 ? 0 : ones;
        }
    }
    while (ones || fives || twenties || fifties || hundreds || fivehundreds || thousands || threethousands || tenthousands || thirtythousands) {
        func_0038CE20(&position, object, 0.0009765625f);
        angle = func_00382538();
        x = func_0038D098(angle) * (func_003824E0(0, 3) * 0.020000001f);
        velocity.x = x;
        y = func_0038D0B0(angle) * (func_003824E0(0, 3) * 0.020000001f);
        velocity.y = y;
        velocity.z = 0;
        velocity.z = func_003824E0(3.700000047683716f, 6) * 0.020000001f;
        half.x = velocity.x; half.y = velocity.y; half.z = 0;
        func_0038CF68(&half, &half, 0.5f);
        vec_add_ab(&position, &position, &half);
        position.z += height;
        if (surface >= 0) {
            duration = 120;
            if ((f32)func_L01_004461B8(&t0, &t1, -0.0021600001f, velocity.z - (-0.0021600001f), position.z - D_L01_0021F6C0[surface]->f18) >= 1 && t0 > 0 && t0 < duration) duration = t0;
            func_0038CE20(&end, &velocity, duration);
            vec_add_ab(&end, &end, object + 16);
            func_L01_00477668(surface, object + 16, &end, &hit);
            vec_sub_ab(&end, &hit, &position);
            end.z = 0;
            func_0038CF68(&correction, &end, 0.25f);
            vec_sub_ab(&end, &end, &correction);
            func_0038CE20(&end, &end, 1 / duration);
            velocity.x = end.x; velocity.y = end.y;
        }
        vec_add_ab(&velocity, &velocity, &offset);
        if (thirtythousands) { func_L01_002F8F20(object, &position, &velocity, flags, 30000, enabled); thirtythousands--; }
        else if (tenthousands) { func_L01_002F8F20(object, &position, &velocity, flags, 10000, enabled); tenthousands--; }
        else if (threethousands) { func_L01_002F8F20(object, &position, &velocity, flags, 3000, enabled); threethousands--; }
        else if (thousands) { func_L01_002F8F20(object, &position, &velocity, flags, 1000, enabled); thousands--; }
        else if (fivehundreds) { func_L01_002F8F20(object, &position, &velocity, flags, 500, enabled); fivehundreds--; }
        else if (hundreds) { func_L01_002F8F20(object, &position, &velocity, flags, 100, enabled); hundreds--; }
        else if (fifties) { func_L01_002F8F20(object, &position, &velocity, flags, 50, enabled); fifties--; }
        else if (twenties) { func_L01_002F8F20(object, &position, &velocity, flags, 20, enabled); twenties--; }
        else if (fives) { func_L01_002F8F20(object, &position, &velocity, flags, 5, enabled); fives--; }
        else { func_L01_002F8F20(object, &position, &velocity, flags, 1, enabled); ones--; }
    }
}
/* localdecomp:end func_L01_0044D360 */

/* localdecomp:start func_L01_0044DF00 */
extern s32 D_00143950[];
extern f32 D_001D5308;
extern f32 D_001D530C;
extern f32 D_001D5310;
extern f32 D_001D5314;
extern f32 D_001D5318;
extern f32 D_001D531C;
extern s32 D_001D5320;
extern f32 D_001D5324;

void func_L01_0044DF00(s32 a0) {
    if (a0 == 0) {
        D_00143950[0] = 0;
        D_001D5308 = 1.0f;
        D_001D530C = 1.0f;
        D_001D5310 = 1.0f;
        D_001D5314 = 0.0166666675f;
        D_001D5318 = 0.000277777785f;
        D_001D531C = 4.62962953e-06f;
        D_001D5320 = 5;
        D_001D5324 = 0.0166666675f;
    } else {
        D_00143950[0] = 1;
        D_001D5308 = 1.20000005f;
        D_001D530C = 1.44000006f;
        D_001D5310 = 0.833333313f;
        D_001D5314 = 0.0200000014f;
        D_001D5318 = 0.000400000019f;
        D_001D531C = 7.99999998e-06f;
        D_001D5320 = 6;
        D_001D5324 = 0.0199999996f;
    }
}
/* localdecomp:end func_L01_0044DF00 */

LINKER_REMNANT("asm/levels", func_L01_0044E020);
