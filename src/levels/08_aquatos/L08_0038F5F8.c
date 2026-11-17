#include "common.h"

typedef struct {
    char pad_000[0x140];
    float x_140;
    float y_144;
    float z_148;
} AimVector_0038F660;

/* localdecomp:start func_L08_0038F5F8 */
extern void func_0038CE20(f32 *, f32 *, f32);
void func_L08_0038F5F8(f32 *m, f32 s) {
    func_0038CE20(m, m, s);
    func_0038CE20(m + 4, m + 4, s);
    func_0038CE20(m + 8, m + 8, s);
    func_0038CE20(m + 12, m + 12, s);
}
/* localdecomp:end func_L08_0038F5F8 */

/* localdecomp:start func_L08_0038F660 */
#include "vu0.h"

extern AimVector_0038F660 D_L08_001E1B80;
extern void func_L01_0039C4D8(char *pkt);
extern long func_00389598(char *p);
extern float func_0038D160(float a, float b);
extern float func_0038CF38(void *p, float *v);
extern void func_0038D328(float *matrix, float *quat);
extern void func_0038CF68(float *dst, float *src, float scale);
extern void func_003D2DA0(char *pkt, float *matrix, int mode);
extern void func_L08_0038F5F8(f32 *m, f32 s);

void func_L08_0038F660(char *pos, int a1, int a2, char *a3, int t0,
                       float fA, float fB, float fC)
{
    char pkt[144];
    float m[16];
    float quat[4];
    float off[4];
    long r;
    func_L01_0039C4D8(pkt);
    r = func_00389598(a3);
    *(long *)(pkt + 136) = ((long)t0 << 2) | 0x8000000040L;
    *(long *)(pkt + 128) = 0xFF9000000260L;
    *(int *)(pkt + 76) = a1 + (a2 << 24);
    *(int *)(pkt + 72) = a1 + (a2 << 24);
    *(int *)(pkt + 68) = a1 + (a2 << 24);
    *(int *)(pkt + 64) = a1 + (a2 << 24);
    *(long *)(pkt + 112) = 0L;
    *(long *)(pkt + 120) = r;
    quat[3] = 0.0f;
    quat[2] = func_0038D160(D_L08_001E1B80.x_140 - *(float *)(pos + 0),
                           D_L08_001E1B80.y_144 - *(float *)(pos + 4));
    quat[1] = -func_0038D160(func_0038CF38(pos, &D_L08_001E1B80.x_140),
                             D_L08_001E1B80.z_148 - *(float *)(pos + 8));
    quat[0] = fB;
    func_0038D328(m, quat);
    vec_sub_ba(off, &D_L08_001E1B80.x_140, pos);
    func_0038CF68(off, off, fC);
    m[12] = *(float *)(pos + 0) + off[0];
    m[13] = *(float *)(pos + 4) + off[1];
    m[14] = *(float *)(pos + 8) + off[2];
    m[15] = 1.0f;
    func_L08_0038F5F8((f32 *)pkt, fA);
    func_003D2DA0(pkt, m, 0);
}
/* localdecomp:end func_L08_0038F660 */
