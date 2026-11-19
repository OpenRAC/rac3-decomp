/* functional: high. Codex near miss, 216 words differ: callee-saved registers, branch layout, reward float conversion order, signed vs unsigned shift of the kill-table nibble (bit 3 unaffected). I changed D_L01_002C5600 to the file's Row type via cast, and func_00382348 to take *hit (retail leaves it in a0). Redeclares S_003DEF68 which the file defines later. */
#include "common.h"
/* localdecomp:start func_L01_003DDDA8 */
extern u8 D_001425C0[];
typedef struct { u8 pad[1]; u8 level; u8 pad2[0x6A]; f32 damage; u8 rest[0x80]; } Row_003DDDA8;
extern u8 *D_L01_001EEA80[];
/* Exact existing later typedef, needed before this block when integrating. */
typedef struct {
    u8 p0[0x1210];
    s32 w1210;
    u8 p1214[0xC];
    s32 w1220;
} S_003DEF68;
extern S_003DEF68 D_001A4BE0;
extern s32 D_00142660[];
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern s32 D_001D545C_sda;
extern u8 D_001BBE90[];
extern u8 D_L01_001D60E0[];
extern u8 D_L01_001D60D8[];
extern u8 D_001426E0[];
extern f32 D_001DAA34_sda;
extern f32 D_L01_002F1600[];
extern u8 D_00142DE0[];
typedef struct { u128_t velocity; u8 pad[0x10]; s32 flags; u8 rest[0xC]; } Damage_003DDDA8;
static __inline__ Row_003DDDA8 *row_003DDDA8(void) {
    return (Row_003DDDA8 *)&D_L01_002C5600[D_001425C0[0x97]];
}
static __inline__ u8 *camera_003DDDA8(S_003DEF68 *g) {
    return *(u8 **)((u8 *)g + 0x25C0);
}
void func_L01_003DDDA8(u8 *obj, u128_t *direction) {
    extern void func_0038CE20(u128_t *, u128_t *, f32);
    extern s32 func_003D4D00(void *, s32, void *, s32, f32);
    extern u8 *func_00382348(u8 *);
    extern s32 func_L01_004006C8(u8 *, u32, s32);
    extern s32 func_L01_0041A4F0(void);
    extern void func_L01_003DE198(void);
    extern void func_L01_00315900(u8 *, s32, void (*)(void));
    extern void func_L01_00446748(Damage_003DDDA8 *, u8 *, s32, f32);
    extern void func_L01_00446978(u8 *, Damage_003DDDA8 *);
    extern void func_L01_003DD9C8(u8 *, void *);
    struct { u128_t impulse; Damage_003DDDA8 damage; u128_t *position; } frame;
    u8 **hit;
    s32 count;
    f32 radius;
    func_0038CE20(&frame.impulse, direction, -3.0f);
    radius = 4.0f;
    if (row_003DDDA8()->level >= 4) radius = 1.0f;
    frame.position = (u128_t *)(obj + 0x10);
    count = func_003D4D00(frame.position, 16, obj, 0, radius);
    if (count != 0) {
        if (count > 0) {
        hit = D_L01_001EEA80;
        do {
            u8 *state;
            if (*hit == camera_003DDDA8(&D_001A4BE0) || *(s16 *)(obj + 0xAA) == 0x1A90) goto next;
            state = func_00382348(*hit);
            if (*hit != 0 && *(u8 **)(*hit + 0x24) != 0 && (*(u8 **)(*hit + 0x24))[0x46] == 5 && state != 0 && state[0xE] != 3) {
                if (*(f32 *)state > row_003DDDA8()->damage) {
                    frame.damage.flags = 1;
                    func_0038CE20(&frame.damage.velocity, (u128_t *)(obj + 0xD0), -1.0f);
                    ((f32 *)&frame.damage.velocity)[3] = 5627.925f;
                    func_L01_00446748(&frame.damage, *hit, 0x110000, row_003DDDA8()->damage);
                    func_L01_00446978(*hit, &frame.damage);
                } else {
                    s32 bonus = (D_00142660[14] + 49) / 50;
                    u16 id = *(u16 *)(*hit + 0xB2);
                    u8 bits = D_001BBE90[((s16)id >> 1) + (D_001D545C << 10)];
                    s32 reward;
                    u8 *kind;
                    if (id & 1) bits >>= 4;
                    kind = (bits & 8) ? D_L01_001D60E0 : D_L01_001D60D8;
                    reward = func_L01_004006C8(kind, *(u16 *)(*hit + 0xB6), *(s16 *)(*hit + 0xB2));
                    reward <<= *((u8 *)&D_001A4BE0 + 0x28C8);
                    if (func_L01_0041A4F0()) {
                        if (D_001D545C_sda == 7 && D_001426E0[0x7B]) reward = (s32)((f32)reward * D_001DAA34_sda);
                        else reward = (s32)((f32)reward * D_L01_002F1600[D_001D545C_sda]);
                    }
                    *(s32 *)(D_00142DE0 + 0x25C) += reward + bonus;
                    func_L01_00315900(*hit, 2, func_L01_003DE198);
                }
            } else if (*hit != 0 && *(u8 **)(*hit + 0x24) != 0 && (*(u8 **)(*hit + 0x24))[0x46] == 5 && state != 0 && state[0xE] == 3) {
                frame.damage.flags = 1;
                func_0038CE20(&frame.damage.velocity, (u128_t *)(obj + 0xD0), -1.0f);
                ((f32 *)&frame.damage.velocity)[3] = 5627.925f;
                func_L01_00446748(&frame.damage, *hit, 0x110000, row_003DDDA8()->damage);
                func_L01_00446978(*hit, &frame.damage);
            } else {
                func_L01_003DD9C8(obj, frame.position);
            }
        next:
            hit++;
        } while (--count != 0);
        }
    } else {
        func_L01_003DD9C8(obj, frame.position);
    }
}
/* localdecomp:end func_L01_003DDDA8 */
