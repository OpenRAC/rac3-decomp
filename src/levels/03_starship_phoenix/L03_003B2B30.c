#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

typedef struct { char pad[0x120]; int idx; } T_003B2B30;
typedef struct { char pad[0x68]; T_003B2B30 *p; } O_003B2B30;

/* localdecomp:start func_L03_003B2B30 */
extern char *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern float D_001DE990_sda;
__asm__(".extern D_001DE990_sda, 4");
extern float D_L03_001DE994[4];
__asm__(".extern D_L03_001DE994, 16");
extern float D_L03_001DE998[4];
__asm__(".extern D_L03_001DE998, 16");
void func_L01_00450DE8(void *, void *, float, float, float);
void func_L03_003B2B30(O_003B2B30 *o) {
    char *t = D_L03_001DF99C + (o->p->idx << 8);
    *(u128_t *)((char *)o + 0xF0) = *(u128_t *)(t + 0xF8);
    func_L01_00450DE8(t, (char *)o + 0x10, D_001DE990_sda, D_L03_001DE994[0], D_L03_001DE998[0]);
}
/* localdecomp:end func_L03_003B2B30 */

/* localdecomp:start func_L03_003B2B88 */
void func_L01_00445130(s32, s32, s32);
void func_L03_003B2B88(s32 arg0) {
    func_L01_00445130(arg0, 4, -1);
}
/* localdecomp:end func_L03_003B2B88 */

/* localdecomp:start func_L03_003B2BA8 */
void func_L01_00445130(s32, s32, s32);
void func_L03_003B2BA8(s32 arg0) {
    func_L01_00445130(arg0, 3, -1);
}
/* localdecomp:end func_L03_003B2BA8 */

/* localdecomp:start func_L03_003B2BC8 */
void func_L01_00445130(s32, s32, s32);
void func_L03_003B2BC8(s32 arg0) {
    func_L01_00445130(arg0, 2, -1);
}
/* localdecomp:end func_L03_003B2BC8 */

/* localdecomp:start func_L03_003B2BE8 */
void func_L01_00445130(s32, s32, s32);
void func_L03_003B2BE8(s32 arg0) {
    func_L01_00445130(arg0, 5, -1);
}
/* localdecomp:end func_L03_003B2BE8 */

/* localdecomp:start func_L03_003B2C08 */
typedef struct { char pad[0x100]; u128_t v; char pad2[0x14]; int flag; } S_003B2C08;
typedef struct { char pad[0x68]; S_003B2C08 *p; } O_003B2C08;
void func_L03_003B2C08(O_003B2C08 *o, u128_t *src) {
    S_003B2C08 *s = o->p;
    if (src == 0) { s->flag = 0; return; }
    s->flag = 1;
    s->v = src[1];
}
/* localdecomp:end func_L03_003B2C08 */
