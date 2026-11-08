/* Near miss, ported from rac4-decomp's func_L00_005535D0 (cross-game near pair). NEAR: SAVE-SLOTS: body already right, but retail frame 0x50 saves s0..s3 and ra at 16-byte spacing (0,0x10,0x20,0x30,0x40; same pattern as func_L39_00500948) while ours packs them in 0x30; couldnt find the source cause (long params made it worse) */
extern void func_L39_00517828(u8 *descriptor, u32 flags, u32 type, u32 properties);
extern void func_L39_00517868(u8 *descriptor, const void *data, u32 length);
void func_L39_005177C0(u8 *descriptor, u32 flags, u32 type, const void *data, u32 length, u32 properties, u32 extraFlags)
{
    func_L39_00517828(descriptor, flags, type, properties);
    func_L39_00517868(descriptor, data, length);
    descriptor[0x16] |= extraFlags;
}
