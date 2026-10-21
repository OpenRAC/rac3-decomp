/* US draft of func_0038DBA0 (rac3-uya-decomp func_00389468, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `-mno-split-addresses` `@ps2as` (a single-function override). */

/* localdecomp:start func_0038DBA0 */
float func_0038DBA0(float first, float second) {
    register float difference __asm__("$f0");
    register float pi __asm__("$f14");
    register float doubled __asm__("$f1");

    difference = first - second;
    pi = 3.1415927f;
    __asm__ volatile(".word 0" : "+f"(pi));
    difference = __builtin_fabsf(difference);
    if (difference < pi) {
        goto done;
    }
    doubled = pi + pi;
    difference = doubled - difference;
done:
    return difference;
}
/* localdecomp:end func_0038DBA0 */
