/* PAL near miss (Codex wave 10): near miss: 2 words differ with the file's flags.
 * Worker's note: 2 word diffs at +0x09C/+0x0A0 (v0 vs v1 cooldown literal/store); build/codex/w518/func_L07_003B5E08.retained.log. Exact void(s32,s32,void*,s32) func_L01_004AAC98 retained; review return-type context correction, no cast/alias workaround. No metadata.
 */
#include "common.h"
/* localdecomp:start func_L07_003B5E08 */
typedef struct { u8 bytes[16]; } Saved_003B5E08;
typedef struct { u8 pad0[0x20]; u8 state; u8 pad21[0x89]; s16 oclass; } M_003B5E08;
typedef struct {
    u8 pad0[0x30]; f32 health; s16 max_health; u8 pad36[0x11]; u8 color;
    u8 pad48[0x16]; u8 flag5E, pad5F, flag60; u8 pad61[0xF]; Saved_003B5E08 damage;
    u8 pad80[0x110]; s32 anim; u8 pad194[0x11C]; u8 bone[0x50]; s32 child_index;
    u8 pad304[4]; M_003B5E08 *child; u8 pad30C[0x15]; u8 phase; u8 pad322[2]; u8 tracking;
    u8 pad325; u8 effect; u8 pad327; s16 timer; u8 pad32A[6]; s16 cooldown;
    u8 pad332[10]; s32 saved;
} State_003B5E08;
extern u8 *D_L07_001DF41C;
extern u8 D_L07_001E1EC0[];
extern u8 D_L07_001D66B0[] __attribute__((section(".sdata")));
void func_L07_003B5E08(u8 *obj)
{
    extern s32 func_L01_00447490(void *, s32, s32);
    extern f32 func_L01_004474E8(void *, s32);
    extern void func_L01_004AAC98(s32, s32, void *, s32);
    extern void func_L01_00459BE8(void *, s32, f32);
    extern void func_003C4A40(void *, void *);
    extern void func_L01_0044ABD0(void *, void *);
    extern void func_L01_0044E820(void *, s32);
    extern s32 func_0038CB00(void *);
    extern s32 func_L07_003A2380(u8, s32, u8, s16);
    extern void func_L07_003B64D0(u8 *, s32);
    extern void func_L01_0043B9E8(void *, s32, s32, s32);
    extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, f32, f32, f32, f32,
                                s32, s32, s32, s32, s32, s32, s32);
    extern void func_L07_003315B0(void *);
    extern void func_L01_0047C990(s32, s32, s32, f32);
    extern void func_L01_00456BD0(void *, s32);
    extern s32 func_L07_00333D20(s32);
    extern void func_L01_00456C98(void *, f32, f32, f32, s32, s32, s32, s32, s32,
                                s32, s32, s32, s32);
    extern void func_L07_003B6870(u8 *);
    extern void func_L07_004522E8(void *, s32, void *, f32);
    extern f32 func_L01_0040E548(void *, void *);
    extern void func_L01_004472C0(void *);
    Saved_003B5E08 saved;
    State_003B5E08 *p = *(State_003B5E08 **)(obj + 0x68);
    Saved_003B5E08 *damage;
    u8 *child;
    f32 amount;
    s32 hit;
    Pool_003AF678 *pool;
    if (obj[0x20] == 1) return;
    hit = func_L01_00447490(obj, -1, 0);
    damage = &p->damage;
    amount = func_L01_004474E8(obj, hit);
    obj[0xA8] = 255;
    if ((*(u16 *)(obj + 0x34) & 0x4000) && amount > 0.0f) {
        if (p->cooldown == 0) {
            func_L01_004AAC98(0, 0, obj, 0x1A1C);
            p->cooldown = 50;
        }
        p->health -= amount;
        func_L01_00459BE8(obj, p->color, amount);
        p->damage.bytes[7] = 255;
        func_003C4A40(obj, damage);
        if ((f32)p->max_health * 0.1f <= amount) {
            child = D_L07_001DF41C + (p->child_index << 8);
            if (child[0xBC] == 0) child[0xBC] = 2;
        }
    }
    func_L01_0044ABD0(obj, damage);
    if (*(s16 *)&p->damage == 0) func_L01_0044E820(obj, p->saved);
    func_0038CB00(&p->cooldown);
    if (p->phase == 0) {
        if (p->health < (f32)p->max_health * 0.66f) {
            func_L07_003A2380(6, (s32)obj, 0, 100);
            func_L07_003B64D0(obj, 18);
            p->phase = 1;
            p->effect = 3;
            p->health = (f32)p->max_health * 0.66f;
        }
    } else if (p->phase == 1) {
        if (p->health < (f32)p->max_health * 0.33f) {
            func_L07_003B64D0(obj, 18);
            p->phase = 2;
            p->effect = 3;
            p->health = (f32)p->max_health * 0.33f;
        }
    }
    if (p->effect) {
        M_003B5E08 *linked = p->child;
        if (linked) {
            if (linked->oclass != 0x1C81 || linked->state == 0xFE || linked->state == 0xFD) p->child = 0;
        } else {
            ((u8 *)((p->child_index << 8) + (s32)D_L07_001DF41C))[0xBC] = p->effect;
            p->effect = 0;
        }
    }
    if (p->health <= 0.0f) {
        saved = p->damage;
        func_L01_0043B9E8(obj, saved.bytes[4], saved.bytes[5], saved.bytes[6]);
        func_L01_00451FE0(obj, 0x3FFF, D_L07_001D66B0,
                          8.0f, 12.0f, 8.0f, 12.0f, -1.0f, -1.0f, 1.0f, 1.0f, 255, 180, 0, 0, 35, 0, 3);
        func_L07_003315B0(obj);
        return;
    }
    if (p->flag5E) {
        func_L07_003315B0(obj);
        p->flag5E = 0;
        return;
    }
    if (p->flag60) {
        func_L07_003315B0(obj);
        p->flag60 = 0;
        return;
    }
    if (p->tracking) {
        Pool_003AF678 *g = (Pool_003AF678 *)D_L07_001E1EC0;
        if (g->w144 != obj && g->w144 == 0) {
            g->w144 = obj;
            g->w148 = 0;
        }
    } else {
        Pool_003AF678 *g = (Pool_003AF678 *)D_L07_001E1EC0;
        if (g->w144 == obj) g->w144 = 0;
    }
    pool = (Pool_003AF678 *)D_L07_001E1EC0;
    func_L01_0047C990(2, 0, pool->w144 != obj, p->health / (f32)p->max_health);
    func_L01_00456BD0(obj, 3);
    hit = func_L07_00333D20(p->anim);
    func_L01_00456C98(obj, 0.0f, 0.0f, 1.0f, hit, 0, 0, 0, 0, 1, 0, 0, 0);
    func_L07_003B6870(obj);
    func_0038CB00(&p->timer);
    func_L07_004522E8(obj, 17, p->bone, 2.5f);
    if (func_L01_0040E548(pool, obj + 0x10) < 5625.0f) {
        func_L01_004472C0(obj);
        obj[0x6F] = 70;
    }
}
/* localdecomp:end func_L07_003B5E08 */
