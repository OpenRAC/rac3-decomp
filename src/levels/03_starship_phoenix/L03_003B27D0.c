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
