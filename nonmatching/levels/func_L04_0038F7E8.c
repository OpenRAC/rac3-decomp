/* NTSC-U draft (2026-11-14, Codex worker): C of func_L04_0038E0D0, the NTSC-U twin of func_L04_0038F7E8, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" when tried; not with src/levels/04_marcadia/L04_0038F7E8.c's current line.
 * Worker's note: 406 diff; permitted GNU assembler emits lit4 instead of retail inline literals 0x3FC90FDB/0x3F860A92/0x3C8EFA35/0x3E32B8C2; register allocation and div padding also differ; full C/VU draft retained; no flags_alt; forbidden flags not tried; best log func_L04_0038E0D0.check01.log
 */
#include "common.h"

/* localdecomp:start func_L04_0038E0D0 */
#include "vu0.h"
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_0038E0D0;

static __inline__ void add_ab_0038E0D0(void *d, void *a, void *b)
{
    __asm__("lqc2 $vf1, %1
	lqc2 $vf2, %2
	vadd.xyz $vf1, $vf1, $vf2
	sqc2 $vf1, %0"
        : "=m"(*(V_0038E0D0 *)d)
        : "m"(*(V_0038E0D0 *)a), "m"(*(V_0038E0D0 *)b) : "vf1", "vf2");
}
static __inline__ void add_ba_0038E0D0(void *d, void *a, void *b)
{
    __asm__("lqc2 $vf2, %2
	lqc2 $vf1, %1
	vadd.xyz $vf2, $vf2, $vf1
	sqc2 $vf2, %0"
        : "=m"(*(V_0038E0D0 *)d)
        : "m"(*(V_0038E0D0 *)a), "m"(*(V_0038E0D0 *)b) : "vf1", "vf2");
}
static __inline__ void sub_ab_0038E0D0(void *d, void *a, void *b)
{
    __asm__("lqc2 $vf1, %1
	lqc2 $vf2, %2
	vsub.xyz $vf1, $vf1, $vf2
	sqc2 $vf1, %0"
        : "=m"(*(V_0038E0D0 *)d)
        : "m"(*(V_0038E0D0 *)a), "m"(*(V_0038E0D0 *)b) : "vf1", "vf2");
}
static __inline__ void sub_ba_0038E0D0(void *d, void *a, void *b)
{
    __asm__("lqc2 $vf2, %1
	lqc2 $vf1, %2
	vsub.xyz $vf2, $vf2, $vf1
	sqc2 $vf2, %0"
        : "=m"(*(V_0038E0D0 *)d)
        : "m"(*(V_0038E0D0 *)a), "m"(*(V_0038E0D0 *)b) : "vf1", "vf2");
}
extern u8 D_001A4BE0[];
extern f32 D_001DDD64_sda, D_001DDD60_sda;
extern s32 D_001D6740_sda;
extern s32 D_L04_001D673C[];
extern V_0038E0D0 D_L04_001E9620;
extern u8 *D_L04_0021D460[], *D_L04_001E9618[];
extern void func_003886E8(void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern u8 *func_0037E0B8(void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_00388800(void *, void *);
extern f32 func_00389468(f32, f32);
extern f32 func_003887C8(void *, void *);
extern f32 func_00388730(void *, void *);
extern f32 func_00388770(void *);
extern f32 func_00388990(f32);
extern void func_0037E4B8(void *, f32, f32, f32);

u8 *func_L04_0038E0D0(u8 *actor, V_0038E0D0 *p, f32 *outYaw, f32 *outPitch)
{
    V_0038E0D0 origin, offset, heroPos;
    u8 *ignored[128];
    V_0038E0D0 targetPos, tmp, ray, projection;
    u8 *actorVars, *selected, *obj, *info, *heroMoby, *hit;
    s32 ignoreCount, index, close, accept, attempts, i;
    f32 best, yaw, pitch, yawDiff, dist, dot, side, len, angle, radius, radiusAngle;
    origin = *p;
    actorVars = *(u8 **)(actor + 0x68);
    best = D_001DDD64_sda;
    selected = 0;
    func_003886E8(&offset, *(u8 **)(D_001A4BE0 + 0x25C0) + 0xE0, 0.5f);
    heroMoby = *(u8 **)(D_001A4BE0 + 0x25C0);
    __asm__("lqc2 $vf2, %2
	lqc2 $vf1, %1
	vadd.xyz $vf1, $vf1, $vf2
	sqc2 $vf1, %0"
        : "=m"(heroPos)
        : "m"(*(V_0038E0D0 *)(heroMoby + 0x10)), "m"(offset) : "vf1", "vf2");
    if (func_003CE740(&heroPos, &origin, 6, heroMoby, 0)) {
        origin = D_L04_001E9620;
        return 0;
    }
    ignoreCount = 0;
    index = 0;
    obj = D_L04_0021D460[index];
    while (obj != 0) {
        if (obj[0x20] == 0xFE || obj[0x20] == 0xFD ||
            *(s16 *)(obj + 0xAA) == 0x1BC3 || *(s16 *)(obj + 0xAA) == 0x189B ||
            *(s16 *)(obj + 0xAA) == 0x1D3E || *(s16 *)(obj + 0xAA) == 0x1A90)
            goto next;
        targetPos = *(V_0038E0D0 *)(obj + 0x10);
        info = func_0037E0B8(obj);
        if (!info || info[0xE] == 3)
            goto next;
        func_003886E8(&tmp, obj + 0xE0, *(f32 *)(info + 0x10));
        add_ab_0038E0D0(&targetPos, &targetPos, &tmp);
        if (!obj || !*(u8 **)(obj + 0x24) || (*(u8 **)(obj + 0x24))[0x46] != 5)
            goto next;
        close = 0;
        yaw = func_00388A28(targetPos.x - origin.x, targetPos.y - origin.y);
        pitch = func_00388A28(func_00388800(&origin, &targetPos), targetPos.z - origin.z);
        yawDiff = func_00389468(*outYaw, yaw);
        dist = func_003887C8(&origin, &targetPos);
        if (D_L04_001D673C[0] != 0 || *(s16 *)(D_001A4BE0 + 0x368) != 0 || D_001D6740_sda != 0) {
            if (dist < 2.5f) {
                heroMoby = *(u8 **)(D_001A4BE0 + 0x25C0);
                sub_ba_0038E0D0(&ray, obj + 0x10, heroMoby + 0x10);
                dot = func_00388730(&ray, heroMoby + 0xE0);
                if (fabs_asm(dot) < 2.0f) {
                    func_003886E8(&projection, *(u8 **)(D_001A4BE0 + 0x25C0) + 0xE0, dot);
                    sub_ab_0038E0D0(&ray, &ray, &projection);
                    side = func_00388730(&ray, *(u8 **)(D_001A4BE0 + 0x25C0) + 0xC0);
                    len = func_00388770(&ray);
                    if (len != 0.0f && 1.5707963705062866f - func_00388990(side / len) < 1.0471975803375244f)
                        close = 1;
                }
            }
        } else {
            if (dist < 2.5f) {
                heroMoby = *(u8 **)(D_001A4BE0 + 0x25C0);
                angle = func_00388A28(*(f32 *)(obj + 0x10) - *(f32 *)(D_001A4BE0 + 0x80),
                    *(f32 *)(obj + 0x14) - *(f32 *)(D_001A4BE0 + 0x84));
                if (func_00389468(*(f32 *)(heroMoby + 0xF8), angle) < 1.0471975803375244f &&
                    fabs_asm(origin.z - targetPos.z) < 2.0f)
                    close = 1;
            }
        }
        if (close && !func_003CE740(&origin, &targetPos, 6, *(u8 **)(D_001A4BE0 + 0x25C0), 0)) {
            selected = obj;
            *outPitch = -pitch;
            *outYaw = yaw;
            break;
        }
        if (best < dist && obj != *(u8 **)(actorVars + 0x10))
            goto next;
        if (D_001DDD64_sda < dist)
            goto next;
        func_0037E4B8(&tmp, dist, *outYaw, *outPitch + *(f32 *)(D_001A4BE0 + 0x344) * 0.5f);
        add_ba_0038E0D0(&tmp, &origin, &tmp);
        angle = func_00388990(func_003887C8(&tmp, &targetPos) / (dist + dist));
        angle += angle;
        if (D_001DDD60_sda * 0.01745329238474369f < angle) {
            info = func_0037E0B8(obj);
            if (info) {
                radius = (f32)info[0xA] * 0.125f;
                radiusAngle = func_00388990(radius / dist);
                if (radius < dist) {
                    angle -= radiusAngle;
                    if (angle < 0.0f)
                        angle = 0.0f;
                }
            }
        }
        if (angle < D_001DDD60_sda * 0.01745329238474369f) {
            accept = 1;
            ray = origin;
            attempts = 0;
            while (func_003CE740(&ray, &targetPos, 6, actor, 0)) {
                attempts++;
                if (attempts >= 7)
                    break;
                hit = D_L04_001E9618[0];
                if (hit && (*(s16 *)(hit + 0xAA) == 0x1BC3 || *(s16 *)(hit + 0xAA) == 0x189B || *(s16 *)(hit + 0xAA) == 0x1D3E)) {
                    ignored[ignoreCount++] = hit;
                    *(s32 *)(hit + 0x98) = 0;
                    if (ignoreCount >= 128)
                        break;
                    ray = D_L04_001E9620;
                } else {
                    if (hit != obj)
                        accept = 0;
                    break;
                }
            }
            if (accept) {
                *outPitch = -pitch;
                best = dist;
                if (yawDiff < 0.1745329201221466f)
                    *outYaw = yaw;
                selected = obj;
                if (obj == *(u8 **)(actorVars + 0x10))
                    return selected;
            }
        }
next:
        index++;
        obj = D_L04_0021D460[index];
    }
    for (i = 0; i < ignoreCount; i++)
        *(s32 *)(ignored[i] + 0x98) = *(s32 *)(*(u8 **)(ignored[i] + 0x24) + 0x10);
    return selected;
}
/* localdecomp:end func_L04_0038E0D0 */
