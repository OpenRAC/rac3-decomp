/* near miss (level 3, Starship Phoenix): 6 differences: same shape and failure as func_L03_003B27D0 (callee func_L01_00450DE8); int side, lq/sq and lui forms match, only the float argument scheduling differs (retail loads $f13/$f14 first and the $gp $f12 in the jal delay slot); about 20 variants tried */
#include "common.h"

/* localdecomp:start func_L03_003B2B30 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { char pad[0x120]; int idx; } T_003B2B30;
typedef struct { char pad[0x68]; T_003B2B30 *p; } O_003B2B30;
extern char *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern float D_001DE990_sda;
__asm__(".extern D_001DE990_sda, 4");
extern float D_L03_001DE994;
__asm__(".extern D_L03_001DE994, 16");
extern float D_L03_001DE998;
__asm__(".extern D_L03_001DE998, 16");
void func_L01_00450DE8(void *, void *, float, float, float);
void func_L03_003B2B30(O_003B2B30 *o) {
    char *t = D_L03_001DF99C + (o->p->idx << 8);
    *(u128_t *)((char *)o + 0xF0) = *(u128_t *)(t + 0xF8);
    func_L01_00450DE8(t, (char *)o + 0x10, D_001DE990_sda, D_L03_001DE994, D_L03_001DE998);
}
/* localdecomp:end func_L03_003B2B30 */
