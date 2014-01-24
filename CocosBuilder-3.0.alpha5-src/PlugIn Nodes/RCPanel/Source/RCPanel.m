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

#import "RCPanel.h"

#define kCloseButtonAlignGap 4

@interface RCPanel ()

-(void) updateCloseButtonPosition;

@end

@implementation RCPanel
@synthesize closeButtonAlignType;

- (id) init
{
    self = [super init];
    if (!self) return NULL;
    
    enableCloseButton = YES;
    
    //closeButtonAlignType = kCloseButtonAlignTopRight;
    
    closeButtonAlignGap = kCloseButtonAlignGap;
    
    titleLabelAlignTop = NO;
    
  //  [self setAnchorPoint:ccp(0.5f, 0.5f)];
    
    backgroundSprite = [[[CCScale9Sprite alloc] init] autorelease];
    [self addChild:backgroundSprite];
    
    closeButton = [[[CCSprite alloc] init] autorelease];
    [self addChild:closeButton z:1];
    
    titleLabel = [CCLabelTTF labelWithString:@"" fontName:@"" fontSize:30];
    [self addChild:titleLabel z:1];
    
    return self;
}

-(void) dealloc
{
    [super dealloc];
}

-(void) setBackgroundSpriteFrame:(CCSpriteFrame*)frame
{
    if (backgroundSprite) {
        [self removeChild:backgroundSprite];
    }
    backgroundSprite = [CCScale9Sprite spriteWithSpriteFrame:frame];
    [self addChild:backgroundSprite];
    [self setContentSize:backgroundSprite.contentSize];
}

-(void) setCancelButtonNormalSpriteFrame:(CCSpriteFrame *)frame
{
    closeButton.displayFrame = frame;
}

-(void) setCancelButtonSelectedSpriteFrame:(CCSpriteFrame *)frame
{

}

-(void) setPanelSize:(CGSize)size
{
    [self setContentSize:size];
    [backgroundSprite setContentSize:size];
    backgroundSprite.position = ccp(size.width/2, size.height/2);
    [self updateCloseButtonPosition];
    
    if (titleLabelAlignTop) {
        CGPoint pos = ccp(self.contentSize.width/2, self.contentSize.height - closeButtonAlignGap - titleLabel.contentSize.height/2);
        titleLabel.position = pos;
    }
}

-(CGSize) getPanelSize
{
    return backgroundSprite.contentSize;
}

-(void) setEnableCloseButton:(bool) var
{
    enableCloseButton = var;
    closeButton.visible = enableCloseButton;
}

-(bool) getEnableCloseButton
{
    return enableCloseButton;
}

-(void) setCloseButtonPosition:(CGPoint) var
{
    closeButton.position = var;
    if (closeButtonAlignType == kCloseButtonAlignTopLeft) {
        CGSize buttonSize = closeButton.contentSize;
        CGSize backgroundSize = backgroundSprite.contentSize;
        CGPoint pos = ccp(buttonSize.width/2 + closeButtonAlignGap
                          , backgroundSize.height - buttonSize.height/2 - closeButtonAlignGap);
        if (closeButton.position.x != pos.x || closeButton.position.y != pos.y) {
            closeButtonAlignType = kCloseButtonAlignNone;
        }
    }
    else if(closeButtonAlignType == kCloseButtonAlignTopRight)
    {
        CGSize buttonSize = closeButton.contentSize;
        CGSize backgroundSize = backgroundSprite.contentSize;
        CGPoint pos = ccp(backgroundSize.width - buttonSize.width/2 - closeButtonAlignGap
                          , backgroundSize.height - buttonSize.height/2 - closeButtonAlignGap);
        if (closeButton.position.x != pos.x || closeButton.position.y != pos.y) {
            closeButtonAlignType = kCloseButtonAlignNone;
        }
    }
    else if(closeButtonAlignType == kCloseButtonAlignBottomLeft)
    {
        CGSize buttonSize = closeButton.contentSize;
        CGPoint pos = ccp(buttonSize.width/2 + closeButtonAlignGap
                          , buttonSize.height/2 + closeButtonAlignGap);
        if (closeButton.position.x != pos.x || closeButton.position.y != pos.y) {
            closeButtonAlignType = kCloseButtonAlignNone;
        }
    }
    else if(closeButtonAlignType == kCloseButtonAlignBottomRight)
    {
        CGSize buttonSize = closeButton.contentSize;
        CGSize backgroundSize = backgroundSprite.contentSize;
        CGPoint pos = ccp(backgroundSize.width - buttonSize.width/2 - closeButtonAlignGap
                          , buttonSize.height/2 + closeButtonAlignGap);
        if (closeButton.position.x != pos.x || closeButton.position.y != pos.y) {
            closeButtonAlignType = kCloseButtonAlignNone;
        }
    }
}

-(CGPoint) getCloseButtonPosition
{
    return closeButton.position;
}

-(void) setCloseButtonAlignType:(int) type
{
    closeButtonAlignType = type;
    [self updateCloseButtonPosition];
}

//-(int) getCloseButtonAlignType
//{
//    return closeButtonAlignType;
//}

-(void) setCloseButtonAlignGap:(int) gap
{
    closeButtonAlignGap = gap;
    [self updateCloseButtonPosition];
}

-(int) getCloseButtonAlignGap
{
    return closeButtonAlignGap;
}

-(void) setFontName:(NSString*)fontName
{
    titleLabel.fontName = fontName;
}

-(NSString*) getFontName:(NSString*)fontName
{
    return titleLabel.fontName;
}

-(void) setFontSize:(float)fontSize
{
    titleLabel.fontSize = fontSize;
}

-(float) getFontSize
{
    return titleLabel.fontSize;
}

-(void) setTitle:(NSString*)title
{
    titleLabel.string = title;
}

-(NSString*) getTitle
{
    return titleLabel.string;
}

-(void) setEnableTitle:(bool) var
{
    titleLabel.visible = var;
}

-(bool) getEnableTitle
{
    return titleLabel.visible;
}

-(void) setTitleAlignTop:(bool) var
{
    titleLabelAlignTop = var;
    if (titleLabelAlignTop) {
        CGPoint pos = ccp(self.contentSize.width/2, self.contentSize.height - closeButtonAlignGap - titleLabel.contentSize.height/2);
        titleLabel.position = pos;
    }
}

-(bool) getTitleAlignTop
{
    return titleLabelAlignTop;
}

-(void) setTitlePosition:(CGPoint) pos
{
    titleLabel.position = pos;
    CGPoint topPos = ccp(self.contentSize.width/2, self.contentSize.height - closeButtonAlignGap - titleLabel.contentSize.height/2);
    if (topPos.x != pos.x && topPos.y != pos.y) {
        titleLabelAlignTop = NO;
    }
}

-(CGPoint) getTitlePosition
{
    return titleLabel.position;
}

-(void) setTitleColor:(ccColor3B)color3
{
    titleLabel.color = color3;
}

-(ccColor3B) getTitleColor
{
    return titleLabel.color;
}

-(void) updateCloseButtonPosition
{
    if (closeButtonAlignType == kCloseButtonAlignTopLeft) {
        CGSize buttonSize = closeButton.contentSize;
        CGSize backgroundSize = backgroundSprite.contentSize;
        CGPoint pos = ccp(buttonSize.width/2 + closeButtonAlignGap
                          , backgroundSize.height - buttonSize.height/2 - closeButtonAlignGap);
        closeButton.position = pos;
    }
    else if(closeButtonAlignType == kCloseButtonAlignTopRight)
    {
        CGSize buttonSize = closeButton.contentSize;
        CGSize backgroundSize = backgroundSprite.contentSize;
        CGPoint pos = ccp(backgroundSize.width - buttonSize.width/2 - closeButtonAlignGap
                          , backgroundSize.height - buttonSize.height/2 - closeButtonAlignGap);
        closeButton.position = pos;
    }
    else if(closeButtonAlignType == kCloseButtonAlignBottomLeft)
    {
        CGSize buttonSize = closeButton.contentSize;
        CGPoint pos = ccp(buttonSize.width/2 + closeButtonAlignGap
                          , buttonSize.height/2 + closeButtonAlignGap);
        closeButton.position = pos;
    }
    else if(closeButtonAlignType == kCloseButtonAlignBottomRight)
    {
        CGSize buttonSize = closeButton.contentSize;
        CGSize backgroundSize = backgroundSprite.contentSize;
        CGPoint pos = ccp(backgroundSize.width - buttonSize.width/2 - closeButtonAlignGap
                          , buttonSize.height/2 + closeButtonAlignGap);
        closeButton.position = pos;
    }
}

@end
