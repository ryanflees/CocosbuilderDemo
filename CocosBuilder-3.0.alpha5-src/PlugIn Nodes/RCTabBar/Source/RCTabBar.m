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

#import "RCTabBar.h"

@interface RCTabBar ()
{
    CCLabelTTF *logLabel;
}

-(void) updateLayout;

@end

@implementation RCTabBar
@synthesize firstTabButtonSpace;
@synthesize tabButtonSpace;
@synthesize tabButtonSize, backgroundSize;
@synthesize tabButtonSelectedFrame, tabButtonNormalFrame;
@synthesize direction;
@synthesize buttonToBarSpace;
@synthesize tabButtonCount;

- (id) init
{
    self = [super init];
    if (!self) return NULL;
    
    tabButtonNormalFrame = nil;
    direction = kTabBarDirectionTop;
  
#define DEAFULT_BUTTON_SPACE 10
    tabButtonSpace = DEAFULT_BUTTON_SPACE;
    
    tabButonArray = [NSMutableArray array];
    [tabButonArray retain];
    
    logLabel = [CCLabelTTF node];
    [self addChild:logLabel z:10];
    logLabel.position = ccp(200,100);

    return self;
}

-(void) dealloc
{
    [super dealloc];
    [tabButtonNormalFrame release];
    [tabButtonSelectedFrame release];
    [tabButonArray release];
}

-(void) setBackgroundFrame:(CCSpriteFrame *)frame
{
    if (backgroundSprite) {
        CGSize contentSize = backgroundSprite.contentSize;
        [self removeChild:backgroundSprite];
        backgroundSprite = [CCScale9Sprite spriteWithSpriteFrame:frame];
        [self addChild:backgroundSprite];
        backgroundSprite.contentSize = contentSize;
        [self updateLayout];
    }
    else
    {
        backgroundSprite = [CCScale9Sprite spriteWithSpriteFrame:frame];
        [self addChild:backgroundSprite];
        [self updateLayout];
    }
}

-(void) setTabButtonSize:(CGSize) size
{
    tabButtonSize = size;
    [self updateLayout];
}

-(void) setBackgroundSize:(CGSize)size
{
    backgroundSize = size;
    backgroundSprite.contentSize = size;
    [self updateLayout];
}

-(void) setTabButtonCount:(int)count
{
    tabButtonCount = count;
    [self updateLayout];
}

-(void) setTabButtonNormalFrame:(CCSpriteFrame *)frame
{
    [tabButtonNormalFrame release];
    tabButtonNormalFrame = [frame retain];
    [self updateLayout];
}

-(void) setTabButtonSelectedFrame:(CCSpriteFrame *)frame
{
    [tabButtonSelectedFrame release];
    tabButtonSelectedFrame = [frame retain];
}


-(void) setTabButtonSpace:(int)space
{
    tabButtonSpace = space;
    [self updateLayout];
}

-(void) setFirstTabButtonSpace:(int)space
{
    firstTabButtonSpace = space;
    [self updateLayout];
}

-(void) setButtonToBarSpace:(int)space
{
    buttonToBarSpace = space;
    [self updateLayout];
}

-(void) setDirection:(int)var
{
    direction = var;
    [self updateLayout];
}

-(void) updateLayout
{
    for (id node in tabButonArray) {
        CCNode *button = (CCNode*)node;
        [self removeChild:button];
    }
    [tabButonArray removeAllObjects];
    if (tabButtonNormalFrame) {
        for (int i=0; i<tabButtonCount; i++) {
            CCScale9Sprite *button = [CCScale9Sprite spriteWithSpriteFrame:tabButtonNormalFrame];
            [tabButonArray addObject:button];
            [self addChild:button];
            button.contentSize = tabButtonSize;

        }
    }

    if (direction == kTabBarDirectionTop) {
        backgroundSprite.position = ccp(backgroundSprite.contentSize.width/2, backgroundSprite.contentSize.height/2);
        int i=0;
        for (id node in tabButonArray) {
            CCNode *button = (CCNode*) node;
            CGPoint pos = ccp(firstTabButtonSpace + button.contentSize.width/2 + (button.contentSize.width + tabButtonSpace)*i,
            backgroundSprite.contentSize.height + button.contentSize.height/2 + buttonToBarSpace);
            i ++;
            button.position = pos;
        }
    }
    else if (direction == kTabBarDirectionLeft)
    {
        backgroundSprite.position = ccp(backgroundSprite.contentSize.width/2 + tabButtonSize.width + buttonToBarSpace
            , backgroundSprite.contentSize.height/2);
        int i=0;
        for (id node in tabButonArray) {
            CCNode *button = (CCNode*) node;
            float distanceFromTop = firstTabButtonSpace + button.contentSize.height/2 + (button.contentSize.height + tabButtonSpace)*i;
            CGPoint pos = ccp(button.contentSize.width/2,
                    backgroundSprite.contentSize.height - distanceFromTop);
            i ++;
            button.position = pos;
        }
    }
    else if (direction == kTabBarDirectionBottom)
    {
        backgroundSprite.position = ccp(backgroundSprite.contentSize.width/2, backgroundSprite.contentSize.height/2 + tabButtonSize.height + buttonToBarSpace);
        int i=0;
        for (id node in tabButonArray) {
            CCNode *button = (CCNode*) node;
            CGPoint pos = ccp(firstTabButtonSpace + button.contentSize.width/2 + (button.contentSize.width + tabButtonSpace)*i,
                              button.contentSize.height/2);
            i ++;
            button.position = pos;
        }
    }
    else if (direction == kTabBarDirectionRight)
    {
        backgroundSprite.position = ccp(backgroundSprite.contentSize.width/2, backgroundSprite.contentSize.height/2);
        int i=0;
        for (id node in tabButonArray) {
            CCNode *button = (CCNode*) node;
            float distanceFromTop = firstTabButtonSpace + button.contentSize.height/2 + (button.contentSize.height + tabButtonSpace)*i;
            CGPoint pos = ccp(backgroundSprite.contentSize.width +  button.contentSize.width/2 + buttonToBarSpace,
                backgroundSprite.contentSize.height - distanceFromTop);
            i ++;
            button.position = pos;
        }
    }
}

@end
