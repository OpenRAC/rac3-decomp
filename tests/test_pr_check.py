"""Source checks must distinguish callback parameters from global pointer storage."""
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent.parent / "tools"))
import pr_check


class VariableDefinitionTest(unittest.TestCase):
    def test_function_prototypes_accept_callback_parameters(self):
        for declaration in (
            "void func_00389D60(void (*callback)(s32), s32 argument)",
            "void func_00389F18(void (*)(s32), s32 argument)",
            "void register_callbacks(void (*callbacks[4])(s32))",
            "void register_callback(void (*callback)(void (*nested)(s32)))",
            "s32 *lookup(s32 index)",
        ):
            with self.subTest(declaration=declaration):
                self.assertFalse(pr_check.is_variable_definition(declaration))

    def test_global_storage_is_still_rejected(self):
        for declaration in (
            "void (*callback)(s32)",
            "void (*callbacks[4])(s32)",
            "static void (*callback)(s32) = 0",
            "void prototype(s32), (*callback)(s32)",
            "s32 value = lookup(1)",
            "s32 value",
        ):
            with self.subTest(declaration=declaration):
                self.assertTrue(pr_check.is_variable_definition(declaration))

    def test_extern_callback_remains_allowed(self):
        self.assertFalse(pr_check.is_variable_definition("extern void (*callback)(s32)"))

    def test_knr_body_ends_before_the_next_global(self):
        code = "void func_003AB038(o, a) void *o; s32 a; { return; } s32 global;"
        statements = list(pr_check.top_level_statements(code))
        self.assertEqual(len(statements), 2)
        self.assertFalse(pr_check.is_variable_definition(statements[0][1]))
        self.assertEqual(statements[1][1], "s32 global")
        self.assertTrue(pr_check.is_variable_definition(statements[1][1]))


if __name__ == "__main__":
    unittest.main()


class JumpTableRodataTest(unittest.TestCase):
    def rodata_errors(self, source):
        pr_check.errors.clear()
        pr_check.check_file(source, "x.c")
        found = [e for e in pr_check.errors if "INCLUDE_RODATA" in e]
        pr_check.errors.clear()
        return found

    def test_stale_jump_table_after_c_is_rejected(self):
        self.assertTrue(self.rodata_errors(
            's32 func_00100000(void) { return 0; }\n'
            'INCLUDE_RODATA("asm/x/rodata", jtbl_00300000);\n'))

    def test_unreferenced_tail_after_c_is_accepted(self):
        self.assertFalse(self.rodata_errors(
            's32 func_00100000(void) { return 0; }\n'
            'INCLUDE_RODATA("asm/x/rodata", D_00300018);\n'))
