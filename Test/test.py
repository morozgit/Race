#import sys
#sys.path.append('/home/user/C++/Race/Let.cpp')
from Let import Let

def test_setLetPsositionX():
    let_instance = Let()
    expected_x = 42.0

    let_instance.setLetPsositionX(expected_x)

    assert let_instance.m_x == expected_x
