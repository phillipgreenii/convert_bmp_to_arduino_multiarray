import unittest

from convert_bmp_to_arduino_multiarray import convertArrayTo16bitValue


class TestConvertArrayTo16bitValue(unittest.TestCase):

    def test_black(self):
        self.assertEqual(convertArrayTo16bitValue([0x00, 0x00, 0x00]), 0x0000)

    def test_white(self):
        self.assertEqual(convertArrayTo16bitValue([0xff, 0xff, 0xff]), 0xffff)

    def test_red(self):
        self.assertEqual(convertArrayTo16bitValue([0xff, 0x00, 0x00]), 0xf800)

    def test_green(self):
        self.assertEqual(convertArrayTo16bitValue([0x00, 0xff, 0x00]), 0x07e0)

    def test_blue(self):
        self.assertEqual(convertArrayTo16bitValue([0x00, 0x00, 0xff]), 0x001f)

    def test_cyan(self):
        self.assertEqual(convertArrayTo16bitValue([0x00, 0xff, 0xff]), 0x07ff)

    def test_magenta(self):
        self.assertEqual(convertArrayTo16bitValue([0xff, 0x00, 0xff]), 0xf81f)

    def test_yellow(self):
        self.assertEqual(convertArrayTo16bitValue([0xff, 0xff, 0x00]), 0xffe0)


if __name__ == '__main__':
    unittest.main()
