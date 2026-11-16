/* PAL near miss (Codex wave 6): near miss: 103 words differ with the file's flags.
 * Worker's note: 62 diff with --divs 2 in func_L16_003E26E8.09.log; table-search loop peeling/registers differ; PAL tables decoded in .tables.txt; no MATCH metadata claim
 */
#include "common.h"
/* localdecomp:start func_L16_003E26E8 */
#include "vu0.h"
void func_L16_003E26E8(Obj_003E2638 *obj, Q_003E2638 *hit) {
    extern void func_0038CF68(void *, void *, f32);
    extern f32 func_0038CE68(void *, void *);
    extern f32 func_0038D0C8(f32);
    extern void func_L16_003E2C88(u8 *, vu0_q *);
    extern void func_L16_003E2E30(u8 *, vu0_q *);
    extern void func_L16_003E2C28(u8 *, vu0_q *, s32);
    extern s32 func_00382468(s32);
    extern void func_L16_003E3068(char *, int);
    extern void func_L14_0035DA48(void *);
    f32 angles[9] = {0.0f, 0.785398185f, 1.57079637f, 2.356194496f, 3.14159274f, 3.92699075f, 4.71238899f, 5.497787f, 6.28318548f};
    u8 a[5] = {4,5,6,7,8};
    u8 b[5] = {4,6,5,7,8};
    u8 c[5] = {6,7,5,4,8};
    u8 d[5] = {7,6,8,5,4};
    u8 e[5] = {8,7,5,6,4};
    u8 f[5] = {8,5,7,6,4};
    u8 g[5] = {5,6,8,7,4};
    u8 h[5] = {5,4,6,8,7};
    u8 *orders[8] = {a,b,c,d,e,f,g,h};
    vu0_v4 v;
    u8 *p = (u8 *)obj->f68;
    f32 angle;
    s32 n, i, j, k, next;
    u8 *order;
    vec_sub_ab(&v, hit, (u8 *)obj + 0x10);
    v.z = 0.0f;
    func_0038CF68(&v, &v, 1.0f);
    angle = fabs_asm(func_0038D0C8(func_0038CE68(&v, (u8 *)obj + 0xD0)) - 1.57079637f);
    if (func_0038CE68(&v, (u8 *)obj + 0xC0) > 0.0f) angle = 6.28318548f - angle;
    n = 9 - (s32)(*(f32 *)p / *(s16 *)(p + 4) * 9.0f);
    angle += 0.392699093f;
    if (n != 0) func_L16_003E2C88((u8 *)obj, (vu0_q *)hit);
    if (n < 7) func_L16_003E2E30((u8 *)obj, (vu0_q *)hit);
    if (n < 5) {
        if (func_00382468(3)) func_L16_003E2C28((u8 *)obj, (vu0_q *)hit, 2);
        for (i=0; i<n; i++) {
            if ((obj->f7C >> i) & 1) func_L16_003E3068((char *)obj, i);
        }
        return;
    damaged:
        func_L14_0035DA48(obj);
        return;
    } else {
        order=b;
        for (j=0; j<8; j=next) {
            next=j+1;
            if (angles[j] < angle && angle <= angles[next]) { order=orders[j]; break; }
        }
        for (k=0; k<5; k++) {
            if (((obj->f7C >> order[k]) & 1) && n + *(s16 *)(p+0x36) >= 10) {
                goto damaged;
            }
        }
    }
}
/* localdecomp:end func_L16_003E26E8 */
