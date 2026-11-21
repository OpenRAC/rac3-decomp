/* functional: high. scheduling only */
#include "common.h"
/* localdecomp:start func_L01_004CA088 */
typedef struct {
    u8 pad0[0x10];
    Vec4_004C4AD8 position;
    u8 pad20[0x8A];
    s16 class_id;
    u8 padAC[0x44];
    Vec4_004C4AD8 rotation;
} Moby_004CA088;
extern Vec4_004C4AD8 D_L01_001E29E0, D_L01_001E29C0;
extern u8 D_L01_001E1135;
extern f32 D_001DB014_sda,D_001DB018_sda,D_001DB01C_sda,D_001DB020_sda,D_001DB024_sda;
__asm__(".extern D_001DB014_sda, 4");
__asm__(".extern D_001DB018_sda, 4");
__asm__(".extern D_001DB01C_sda, 4");
__asm__(".extern D_001DB020_sda, 4");
__asm__(".extern D_001DB024_sda, 4");
void func_L01_004CA088(Moby_004CA088 *moby) {
    extern void func_0038CE20(Vec4_004C4AD8 *,Vec4_004C4AD8 *,f32);
    extern f32 func_0038DAB8(f32,f32);
    extern void func_0038D308(Vec4_004C4AD8 *,Vec4_004C4AD8 *);
    extern void func_003C7C38(void *);
    extern void func_L01_004CA710(Moby_004CA088 *);
    Vec4_004C4AD8 offset;
    Vec4_004C4AD8 matrix[3];
    Vec4_004C4AD8 temp;
    f32 distance;
    Vec4_004C4AD8 *axis;
    s32 special=0, big;
    if (moby->class_id == 0xC5A || moby->class_id == 0xA65) special=1;
    big=0;
    if (moby->class_id == 0x879 || moby->class_id == 0xAF6 || moby->class_id == 0x907 || moby->class_id == 0xE7A || special) big=1;
    if (special) func_0038CE20(&offset,&D_L01_001E29E0,2.5f);
    else if (big) func_0038CE20(&offset,&D_L01_001E29E0,2.0f);
    else func_0038CE20(&offset,&D_L01_001E29E0,3.0f);
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(moby->position) : "m"(offset), "m"(D_L01_001E29C0) : "vf1", "vf2");
    if (D_L01_001E1135) moby->rotation.x=func_0038DAB8(moby->rotation.x,0.03490658476948738f);
    else moby->rotation.z=func_0038DAB8(moby->rotation.z,0.03490658476948738f);
    func_0038D308(matrix,&moby->rotation);
    if (D_L01_001E1135) {
        if (big) {
            func_0038CE20(&temp,&matrix[1],D_001DB024_sda);
            __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(moby->position) : "m"(temp), "m"(moby->position) : "vf1", "vf2");
            distance=D_001DB020_sda;
        } else {
            func_0038CE20(&temp,&matrix[1],D_001DB018_sda);
            __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(moby->position) : "m"(temp), "m"(moby->position) : "vf1", "vf2");
            distance=D_001DB014_sda;
        }
        axis=&matrix[0];
    } else {
        axis=&matrix[2];
        distance=D_001DB01C_sda;
    }
    func_0038CE20(&temp,axis,distance);
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(moby->position) : "m"(moby->position), "m"(temp) : "vf1", "vf2");
    func_003C7C38(moby);
    func_L01_004CA710(moby);
}
/* localdecomp:end func_L01_004CA088 */
