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

#import "RCEditBox.h"

@implementation RCEditBox
@synthesize editSize;
@synthesize string;
@synthesize inputMode;
@synthesize fontName;
@synthesize fontSize;
@synthesize maxLength;
@synthesize inputFlag;
@synthesize textColor;
@synthesize textPosition;
@synthesize returnType;

- (id) init
{
    self = [super init];
    if (!self) return NULL;
    
    backgroundImage = nil;
    editSize = CGSizeMake(200, 70);
    textPosition = ccp(0, 0);
    
    label = [CCLabelTTF labelWithString:@"" fontName:@"" fontSize:25];
    [self addChild:label z:1];
    
    return self;
}

-(void) dealloc
{
    [super dealloc];
    [string release];
    [fontName release];
}

-(void) setBackgroundFrame:(CCSpriteFrame*) frame
{
    if (backgroundImage) {
        [self removeChild:backgroundImage];
    }
    
    backgroundImage = [CCScale9Sprite spriteWithSpriteFrame:frame];
    [self addChild:backgroundImage];
    backgroundImage.contentSize = editSize;
    backgroundImage.position = ccp(backgroundImage.contentSize.width/2, backgroundImage.contentSize.height/2);
    label.position = ccp( backgroundImage.position.x + textPosition.x
                         , backgroundImage.position.y + textPosition.y);
}

-(void) setEditSize:(CGSize)size
{
    editSize = size;
    backgroundImage.contentSize = size;
    self.contentSize = size;
    backgroundImage.position = ccp(backgroundImage.contentSize.width/2, backgroundImage.contentSize.height/2);
    label.position = ccp( backgroundImage.position.x + textPosition.x
                         , backgroundImage.position.y + textPosition.y);
}

-(void) setString:(NSString *)var
{
    [string release];
    string = [var retain];
    [label setString:string];
}

-(void) setFontSize:(float)var
{
    fontSize = var;
    [label setFontSize:fontSize];
}

-(void) setFontName:(NSString *)var
{
    [fontName release];
    fontName = [var retain];
    [label setFontName:fontName];
}

-(void) setTextColor:(ccColor3B)var
{
    textColor = var;
    label.color = textColor;
}

-(void) setTextPosition:(CGPoint)var
{
    textPosition = var;
    label.position = ccp( backgroundImage.position.x + textPosition.x
                         , backgroundImage.position.y + textPosition.y);
}

@end
