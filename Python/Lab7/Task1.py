class BigBell:
    is_ding = True
    def sound(self):
        if self.is_ding:
            print('ding')
        else:
            print('dong')
        self.is_ding = not self.is_ding

bell = BigBell()
bell.sound()
bell.sound()
bell.sound()