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

#import "RCCheckButton.h"

@interface RCCheckButton ()
{
}

@end

@implementation RCCheckButton
@synthesize selected;

-(id) init
{
    self = [super init];
    if (!self) return NULL;
    buttonSprite = [[[CCSprite alloc] init] autorelease];
    [self addChild:buttonSprite];
    
    label = [[[CCLabelTTF alloc] init] autorelease];
    [self addChild:label];
    label.position = ccp(50, 0);

    return self;
}

-(void) dealloc
{
    [super dealloc];
    [selectedFrame release];
    [normalFrame release];
}

-(void) setNormalSpriteFrame:(CCSpriteFrame*)frame
{
    [normalFrame release];
    normalFrame = [frame retain];
    if (!selected) {
        [buttonSprite setDisplayFrame:normalFrame];
    }
}

-(void) setSelectedSpriteFrame:(CCSpriteFrame*)frame
{
    [selectedFrame release];
    selectedFrame = [frame retain];
    if (selected) {
        [buttonSprite setDisplayFrame:selectedFrame];
    }
}

-(void) setSelected:(bool)var
{
    selected = var;
    if (selected) {
        if (selectedFrame) {
            [buttonSprite setDisplayFrame:selectedFrame];
        }
    }
    else
    {
        if (normalFrame) {
            [buttonSprite setDisplayFrame:normalFrame];
        }
    }
}

-(void) setString:(NSString*)str
{
    label.string = str;
}

-(NSString*) getString
{
    return label.string;
}

-(void) setFontName:(NSString*)fontName
{
    label.fontName = fontName;
}

- (NSString*) getFontName:(NSString*)fontName
{
    return label.fontName;
}

-(void) setFontSize:(float)fontSize
{
    label.fontSize = fontSize;
}

-(float) fontSize
{
    return label.fontSize;
}

-(void) setLabelPosition:(CGPoint) pos
{
    label.position = pos;
}

-(CGPoint) getLabelPosition
{
    return label.position;
}

-(void) setLabelColor:(ccColor3B)color3
{
    label.color = color3;
}

-(ccColor3B) getLabelColor
{
    return label.color;
}

-(void) setSelectedLabelColor:(ccColor3B)color3
{
    selectedColor = color3;
}

-(ccColor3B) getSelectedLabelColor
{
    return selectedColor;
}

-(void) setImageScale:(float)scale
{
    buttonSprite.scale = scale;
}

-(float) getImageScale
{
    return buttonSprite.scale;
}

-(void) setImageScaleX:(float) scaleX
{
    buttonSprite.scaleX = scaleX;
}

-(float) getImageScaleX
{
    return buttonSprite.scaleX;
}

-(void) setImageScaleY:(float) scaleY
{
    buttonSprite.scaleY = scaleY;
}

-(float) getImageScaleY
{
    return buttonSprite.scaleY;
}

@end
