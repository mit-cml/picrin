// -*- mode: objc; c-basic-offset: 2; -*-
// Copyright 2016-2023 MIT, All rights reserved
// Released under the Apache License, Version 2.0
// http://www.apache.org/licenses/LICENSE-2.0

#import "YailList.h"
#include "picrin.h"

@interface YailList () {
 @private
  pic_state *pic;
  pic_value list;
}

@end

@implementation YailList

@synthesize picrinList = list;

- (instancetype)init:(pic_value)list :(pic_state *)state {
  if (self = [super init]) {

  }
  return self;
}

+ (instancetype)makeList:(pic_value)list :(pic_state *)state {
  return [[self alloc] init:list :state];
}

- (void)insertObject:(id)anObject atIndex:(NSUInteger)index {

}

- (void)removeObjectAtIndex:(NSUInteger)index {

}

- (void)addObject:(id)anObject {

}

- (void)removeLastObject {

}

- (void)replaceObjectAtIndex:(NSUInteger)index withObject:(id)anObject {

}

- (NSUInteger)count {
  return 0;
}

- (id)objectAtIndex:(NSUInteger)index {
  return nil;
}

- (instancetype)copyWithZone:(NSZone *)zone {
  return self;
}

- (instancetype)mutableCopyWithZone:(NSZone *)zone {
  return self;
}

@end
