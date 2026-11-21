/* PAL near miss (sol-3): 167 words differ with the file's flags. Saved-register allocation improves with named endpoint pointers. The renderer's copies and VU0 scheduling still differ. */
#include "common.h"
/* localdecomp:start func_L07_003A8538 */
typedef int Q_003A8538 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_003A8538;
typedef struct {
    Q_003A8538 vertices[4];
    s32 colors[4];
    f32 uv[4][2];
    unsigned long state[4];
} Packet_003A8538;
extern s32 D_001DE408_sda, D_001DE3F8_sda, D_001DE3FC_sda;
extern f32 D_001DE400_sda, D_001DE404_sda;
extern V_003A8538 D_L07_001E1E40;
__asm__(".extern D_001DE408_sda, 4");
__asm__(".extern D_001DE3F8_sda, 4");
__asm__(".extern D_001DE3FC_sda, 4");
__asm__(".extern D_001DE400_sda, 4");
__asm__(".extern D_001DE404_sda, 4");

static __inline__ V_003A8538 sub_003A8538(V_003A8538 *a, V_003A8538 *b) {
    V_003A8538 r;
    __asm__ (
        "lqc2 $vf2, 0(%2)\n"
        "lqc2 $vf1, 0(%1)\n"
        "vsub.xyz $vf1, $vf1, $vf2\n"
        "sqc2 $vf1, %0\n"
        : "=m"(r) : "r"(a), "r"(b) : "memory");
    return r;
}

static __inline__ V_003A8538 add_003A8538(V_003A8538 *a, V_003A8538 *b) {
    V_003A8538 r;
    __asm__ (
        "lqc2 $vf2, 0(%2)\n"
        "lqc2 $vf1, 0(%1)\n"
        "vadd.xyz $vf1, $vf1, $vf2\n"
        "sqc2 $vf1, %0\n"
        : "=m"(r) : "r"(a), "r"(b) : "memory");
    return r;
}


static __inline__ void direct_sub_003A8538(V_003A8538 *d, V_003A8538 *a, V_003A8538 *b) {
    __asm__ (
        "lqc2 $vf2, 0(%2)\n"
        "lqc2 $vf1, 0(%1)\n"
        "vsub.xyz $vf1, $vf1, $vf2\n"
        "sqc2 $vf1, %0\n"
        : "=m"(*d) : "r"(a), "r"(b) : "memory");
}
void func_L07_003A8538(u8 *moby, Q_003A8538 *a, Q_003A8538 *b) {
    extern void func_003D93B0(void *, s32, s32, s32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_003D2DA0(void *, s32, s32);
    V_003A8538 pos, end;
    Packet_003A8538 packet;
    V_003A8538 sideA, sideB, direction, temp;
    V_003A8538 *start = &pos, *finish = &end;
    u8 *p;
    f32 *uv;
    s32 i;
    *(Q_003A8538 *)start = *a;
    *(Q_003A8538 *)finish = *b;
    p = *(u8 **)(moby + 0x68);
    func_003D93B0(&packet, D_001DE408_sda, 1, 128);
    packet.colors[3] = D_001DE3F8_sda;
    packet.colors[2] = packet.colors[3];
    packet.colors[1] = packet.colors[3];
    packet.colors[0] = packet.colors[3];
    packet.uv[0][0] = 0.0f;
    packet.uv[0][1] = 0.0f;
    packet.uv[1][0] = 0.0f;
    packet.uv[1][1] = 1.0f;
    packet.uv[2][0] = 1.0f;
    packet.uv[2][1] = 0.0f;
    packet.uv[3][0] = 1.0f;
    packet.uv[3][1] = 1.0f;
    uv = &packet.uv[0][0];
    for (i = 3; i >= 0; i--) {
        *uv -= *(f32 *)(p + 0x2B0);
        if (*uv <= 7.0f) *uv += 7.0f;
        uv += 2;
    }
    direct_sub_003A8538(&direction, start, finish);
    func_0038CF68(&direction, &direction, 1.0f);
    __asm__ (
        "lqc2 $vf2, %3\n"
        "lqc2 $vf1, 0(%2)\n"
        "vsub.xyz $vf1, $vf1, $vf2\n"
        "sqc2 $vf1, %0\n"
        "lqc2 $vf1, 0(%4)\n"
        "vsub.xyz $vf1, $vf1, $vf2\n"
        "sqc2 $vf1, %1\n"
        : "=m"(sideA), "=m"(sideB)
        : "r"(start), "m"(D_L07_001E1E40), "r"(finish) : "memory");
    func_0038CE90(&sideA, &sideA, &direction);
    func_0038CF68(&sideA, &sideA, D_001DE400_sda);
    func_0038CE90(&sideB, &sideB, &direction);
    func_0038CF68(&sideB, &sideB, D_001DE404_sda);
    temp = sub_003A8538(start, &sideA);
    packet.vertices[0] = *(Q_003A8538 *)&temp;
    temp = add_003A8538(start, &sideA);
    packet.vertices[1] = *(Q_003A8538 *)&temp;
    temp = sub_003A8538(finish, &sideB);
    packet.vertices[2] = *(Q_003A8538 *)&temp;
    temp = add_003A8538(finish, &sideB);
    packet.vertices[3] = *(Q_003A8538 *)&temp;
    func_003D2DA0(&packet, 0, 0);
    func_003D93B0(&packet, 14, 1, 128);
    packet.colors[3] = D_001DE3FC_sda;
    packet.colors[2] = packet.colors[3];
    packet.colors[1] = packet.colors[3];
    packet.colors[0] = packet.colors[3];
    packet.uv[0][0] = 0.0f;
    packet.uv[0][1] = 0.0f;
    packet.uv[1][0] = 0.0f;
    packet.uv[1][1] = 1.0f;
    packet.uv[2][0] = 1.0f;
    packet.uv[2][1] = 0.0f;
    packet.uv[3][0] = 1.0f;
    packet.uv[3][1] = 1.0f;
    uv = &packet.uv[0][0];
    for (i = 3; i >= 0; i--) {
        *uv -= *(f32 *)(p + 0x2B0);
        if (*uv <= 7.0f) *uv += 7.0f;
        uv += 2;
    }
    direct_sub_003A8538(&direction, start, finish);
    func_0038CF68(&direction, &direction, 1.0f);
    __asm__ (
        "lqc2 $vf2, %3\n"
        "lqc2 $vf1, 0(%2)\n"
        "vsub.xyz $vf1, $vf1, $vf2\n"
        "sqc2 $vf1, %0\n"
        "lqc2 $vf1, 0(%4)\n"
        "vsub.xyz $vf1, $vf1, $vf2\n"
        "sqc2 $vf1, %1\n"
        : "=m"(sideA), "=m"(sideB)
        : "r"(start), "m"(D_L07_001E1E40), "r"(finish) : "memory");
    func_0038CE90(&sideA, &sideA, &direction);
    func_0038CF68(&sideA, &sideA, D_001DE400_sda * 0.5f);
    func_0038CE90(&sideB, &sideB, &direction);
    func_0038CF68(&sideB, &sideB, D_001DE404_sda * 0.5f);
    temp = sub_003A8538(start, &sideA);
    packet.vertices[0] = *(Q_003A8538 *)&temp;
    temp = add_003A8538(start, &sideA);
    packet.vertices[1] = *(Q_003A8538 *)&temp;
    temp = sub_003A8538(finish, &sideB);
    packet.vertices[2] = *(Q_003A8538 *)&temp;
    temp = add_003A8538(finish, &sideB);
    packet.vertices[3] = *(Q_003A8538 *)&temp;
    func_003D2DA0(&packet, 0, 0);
}
/* localdecomp:end func_L07_003A8538 */
