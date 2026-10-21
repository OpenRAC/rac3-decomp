/* Near miss of func_003A9440 with its file's own flags: tools/check.py reports 43 diff
   (the version it replaces: 45).
*/

/* PAL candidate for func_003A9440 (frontbin).
   The command-list writer.  The packet pointer lives at 0x001DA050.
   Retail reads it with %hi/%lo (the declaration it uses is bigger than the
   $gp window, so the compiler materialises the address absolutely and loads
   it directly) and writes the advanced pointer back through the small
   (4 byte) declaration of the same address, which is $gp-relative.
   Both names below are 0x001DA050. */

/* localdecomp:start func_003A9440 */
typedef struct {
    u32 *cmd; /* the packet pointer */
    u32 pad[2];
} S_1DA050_003A9440;
/* the packet pointer, reloaded after every store */
extern S_1DA050_003A9440 D_001DA050_00389598;
extern u32 *D_001DA050_003A9440;
void func_003A9440(s32 a0, unsigned long a1) {
    D_001DA050_00389598.cmd[0] = 0x10000002;
    D_001DA050_00389598.cmd[1] = 0;
    D_001DA050_00389598.cmd[2] = 0;
    D_001DA050_00389598.cmd[3] = 0x50000002;
    D_001DA050_00389598.cmd[4] = 0x8001;
    D_001DA050_00389598.cmd[5] = 0x10000000;
    D_001DA050_00389598.cmd[6] = 0xE;
    D_001DA050_00389598.cmd[7] = 0;
    *(unsigned long *)&D_001DA050_00389598.cmd[8] = a1;
    D_001DA050_00389598.cmd[10] = a0;
    D_001DA050_00389598.cmd[11] = 0;
    D_001DA050_003A9440 = D_001DA050_00389598.cmd + 12;
}
/* localdecomp:end func_003A9440 */
