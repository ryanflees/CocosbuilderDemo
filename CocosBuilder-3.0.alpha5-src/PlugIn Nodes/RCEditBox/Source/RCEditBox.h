/*
 * CocosBuilder: http://www.cocosbuilder.com
 *
 * Copyright (c) 2012 Zynga Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#import "cocos2d.h"
#import "CCControlButton.h"
#import "CCScale9Sprite.h"

enum EditBoxInputMode
{
    kEditBoxInputModeAny = 0,
    kEditBoxInputModeEmailAddr,
    kEditBoxInputModeNumeric,
    kEditBoxInputModePhoneNumber,
    kEditBoxInputModeUrl,
    kEditBoxInputModeDecimal,
    kEditBoxInputModeSingleLine
};

@interface RCEditBox : CCNode
{
    CCScale9Sprite* backgroundImage;
    CCLabelTTF* label;
}

@property (nonatomic) CGSize editSize;
@property (nonatomic,retain) NSString* string;
@property (nonatomic) int inputMode;
@property (nonatomic) int inputFlag;
@property (nonatomic) float fontSize;
@property (nonatomic,retain) NSString* fontName;
@property (nonatomic) int maxLength;
@property (nonatomic) ccColor3B textColor;
@property (nonatomic) CGPoint textPosition;
@property (nonatomic) int returnType;

-(void) setBackgroundFrame:(CCSpriteFrame*) frame;

@end
