#include "common.h"

typedef int u128_27D0 __attribute__((mode(TI)));
typedef struct { char pad[0x120]; int idx; } T_003B27D0;
typedef struct { char pad[0x68]; T_003B27D0 *p; } O_003B27D0;

/* localdecomp:start func_L03_003B27D0 */
extern char *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern float D_001DE980_sda;
__asm__(".extern D_001DE980_sda, 4");
extern float D_L03_001DE984[4];
__asm__(".extern D_L03_001DE984, 16");
extern float D_L03_001DE988[4];
__asm__(".extern D_L03_001DE988, 16");
void func_L01_00450DE8(void *, void *, float, float, float);
void func_L03_003B27D0(O_003B27D0 *o) {
    char *t = D_L03_001DF99C + (o->p->idx << 8);
    *(u128_27D0 *)((char *)o + 0xF0) = *(u128_27D0 *)(t + 0xF0);
    func_L01_00450DE8(t, (char *)o + 0x10, D_001DE980_sda, D_L03_001DE984[0], D_L03_001DE988[0]);
}
/* localdecomp:end func_L03_003B27D0 */

/* localdecomp:start func_L03_003B2828 */
void func_L01_00445130(s32, s32, s32);
void func_L03_003B2828(s32 arg0) {
    func_L01_00445130(arg0, 5, -1);
}
/* localdecomp:end func_L03_003B2828 */

/* localdecomp:start func_L03_003B2848 */
void func_L01_00445130(s32, s32, s32);
void func_L03_003B2848(s32 arg0) {
    func_L01_00445130(arg0, 4, -1);
}
/* localdecomp:end func_L03_003B2848 */

/* localdecomp:start func_L03_003B2868 */
void func_L01_00445130(s32, s32, s32);
void func_L03_003B2868(s32 arg0) {
    func_L01_00445130(arg0, 3, -1);
}
/* localdecomp:end func_L03_003B2868 */

/* localdecomp:start func_L03_003B2888 */
void func_L01_00445130(s32, s32, s32);
void func_L03_003B2888(s32 arg0) {
    func_L01_00445130(arg0, 6, -1);
}
/* localdecomp:end func_L03_003B2888 */

/* localdecomp:start func_L03_003B28A8 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { char pad[0x100]; u128_t v; char pad2[0x14]; int flag; } S_003B28A8;
typedef struct { char pad[0x68]; S_003B28A8 *p; } O_003B28A8;
void func_L03_003B28A8(O_003B28A8 *o, u128_t *src) {
    S_003B28A8 *s = o->p;
    if (src == 0) { s->flag = 0; return; }
    s->flag = 1;
    s->v = src[1];
}
/* localdecomp:end func_L03_003B28A8 */
