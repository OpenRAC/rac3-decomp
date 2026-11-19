/* functional: high. Positions two menu widgets (0x20017, 0x20018) for the text id a0 (0xED36, 0xED37 or 0xED4B: widgets at 0.1 horizontally and a vertical position offset by D_001D7FD0_sda for the first two ids, 0.854 fixed for the third), after setting widget 0x20016's text to a0; then flags widget 0x20017 if a1 and 0x20018 if a2 via func_L01_00516AA0(id, 1, 1). Same call order as retail. */
/* localdecomp:start func_L39_005DAC98 */
extern f32 D_001D7FD0_sda;
extern void func_L01_00516470(s32, f32, f32);

void func_L39_005DAC98(s32 a0, s32 a1, s32 a2) {
    func_L01_00517190(0x20016, a0);
    if (a0 == 0xED36) {
        func_L01_00516470(0x20017, 0.1f, D_001D7FD0_sda + 0.866f);
        func_L01_00516470(0x20018, 0.1f, D_001D7FD0_sda + 0.91f);
    } else if (a0 == 0xED37) {
        func_L01_00516470(0x20017, 0.1f, D_001D7FD0_sda + 0.854f);
        func_L01_00516470(0x20018, 0.1f, D_001D7FD0_sda + 0.89f);
    } else if (a0 == 0xED4B) {
        func_L01_00516470(0x20017, 0.1f, 0.854f);
    }
    if (a1 != 0) {
        func_L01_00516AA0(0x20017, 1, 1);
    }
    if (a2 != 0) {
        func_L01_00516AA0(0x20018, 1, 1);
    }
}
/* localdecomp:end func_L39_005DAC98 */
