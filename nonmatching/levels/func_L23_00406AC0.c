/* PAL point-history draft: 62 differing instruction words with the owning
 * file's flags; 16 bytes short. Separate counters for the fill and update
 * branches improve the initial 73-word result. The first loop still loads
 * its source quad inside the loop; the second loop merges the source and
 * destination induction pointers and keeps the 0x60 stride in a saved register.
 * Snapshot, pointer-increment, typed-array and byte-copy variants did not
 * improve this result. The function remains assembly.
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L23_00406AC0 */
extern s32 D_L23_001E5DB4[];
extern u8 D_L23_001EE290[];
extern void func_003C2EC0(void *, s32, Mtx4 *);
extern void func_003C4098(void *out, void *a, void *b, f32 t);

void func_L23_00406AC0(void *a0) {
    Mtx4 m;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 *q;
    s32 i;
    s32 j;

    if (D_L23_001E5DB4[0] == 1) {
        s32 fill;
        for (i = 0; i < 9; i++) {
            func_003C2EC0(a0, i, &m);
            q = (vu0_v4 *)(D_L23_001EE290 + i * 0x60);
            for (fill = 0; fill < 6; fill++) {
                *(vu0_q *)&q[fill] = *(vu0_q *)&m.m[3];
            }
        }
    } else if (D_L23_001E5DB4[0] < 0xFA) {
        s32 point;
        for (point = 0; point < 9; point++) {
            q = (vu0_v4 *)(D_L23_001EE290 + point * 0x60);
            for (j = 5; j > 0; j--) {
                *(vu0_q *)&a = *(vu0_q *)&q[j - 1];
                *(vu0_q *)&b = *(vu0_q *)&q[j];
                func_003C4098(&q[j], &a, &b, 0.85f);
            }
            func_003C2EC0(a0, point, &m);
            *(vu0_q *)(D_L23_001EE290 + point * 0x60) = *(vu0_q *)&m.m[3];
        }
    }
}

/* localdecomp:end func_L23_00406AC0 */
