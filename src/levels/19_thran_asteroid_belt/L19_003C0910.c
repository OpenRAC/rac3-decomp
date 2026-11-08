#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct { char p[0x444]; int f444; char q[0x470-0x448]; u128_t v; } B;
typedef struct { char p[0x10]; u128_t v; char q[0x68-0x20]; B *b; } A;

/* localdecomp:start func_L19_003C0910 */
extern void func_L19_003C2628(char *, float, char *, int);

void func_L19_003C0910(char *arg0)
{
    func_L19_003C2628(arg0, *(float *)(arg0 + 0xF8), arg0 + 0x10, 0);
}
/* localdecomp:end func_L19_003C0910 */
