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
#import "CCScale9Sprite.h"

enum
{
    kCloseButtonAlignNone = 0,
    kCloseButtonAlignTopLeft = 1,
    kCloseButtonAlignTopRight = 2,
    kCloseButtonAlignBottomLeft = 3,
    kCloseButtonAlignBottomRight = 4
};

@interface RCPanel : CCNode
{
    bool enableCloseButton;
    CCScale9Sprite *backgroundSprite;
    CCSprite *closeButton;
    CCLabelTTF *titleLabel;
    int closeButtonAlignType;
    int closeButtonAlignGap;
    bool titleLabelAlignTop;
}

@property (nonatomic) int closeButtonAlignType;

-(void) setBackgroundSpriteFrame:(CCSpriteFrame*)frame;

-(void) setCancelButtonNormalSpriteFrame:(CCSpriteFrame*)frame;

-(void) setCancelButtonSelectedSpriteFrame:(CCSpriteFrame*)frame;

-(void) setPanelSize:(CGSize)size;

-(CGSize) getPanelSize;

-(void) setEnableCloseButton:(bool) var;

-(bool) getEnableCloseButton;

-(void) setCloseButtonPosition:(CGPoint) pos;

-(CGPoint) getCloseButtonPosition;

-(void) setCloseButtonAlignGap:(int) gap;

-(int) getCloseButtonAlignGap;

-(void) setFontName:(NSString*)fontName;

-(NSString*) getFontName:(NSString*)fontName;

-(void) setFontSize:(float)fontSize;

-(float) getFontSize;

-(void) setTitle:(NSString*)title;

-(NSString*) getTitle;

-(void) setEnableTitle:(bool) var;

-(bool) getEnableTitle;

-(void) setTitleAlignTop:(bool) var;

-(bool) getTitleAlignTop;

-(void) setTitlePosition:(CGPoint) pos;

-(CGPoint) getTitlePosition;

-(void) setTitleColor:(ccColor3B)color3;

-(ccColor3B) getTitleColor;

@end
