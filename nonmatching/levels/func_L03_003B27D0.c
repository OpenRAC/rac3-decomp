/* near miss (level 3, Starship Phoenix): 6 differences: int side, lq/sq and lui forms match; only the order of the float argument loads differs (retail: $f13, $f14 via lui $at, then $f12 from $gp in the jal delay slot); locals, statement order, return type and unsized/16-byte arrays tried */
#include "common.h"

/* localdecomp:start func_L03_003B27D0 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { char pad[0x120]; int idx; } T_003B27D0;
typedef struct { char pad[0x68]; T_003B27D0 *p; } O_003B27D0;
extern char *D_001DF99C;
__asm__(".extern D_001DF99C, 16");
extern float D_001DE980_sda;
__asm__(".extern D_001DE980_sda, 4");
extern float D_001DE984;
__asm__(".extern D_001DE984, 16");
extern float D_001DE988;
__asm__(".extern D_001DE988, 16");
void func_L01_00450DE8(void *, void *, float, float, float);
void func_L03_003B27D0(O_003B27D0 *o) {
    char *t = D_001DF99C + (o->p->idx << 8);
    *(u128_t *)((char *)o + 0xF0) = *(u128_t *)(t + 0xF0);
    func_L01_00450DE8(t, (char *)o + 0x10, D_001DE980_sda, D_001DE984, D_001DE988);
}
/* localdecomp:end func_L03_003B27D0 */
