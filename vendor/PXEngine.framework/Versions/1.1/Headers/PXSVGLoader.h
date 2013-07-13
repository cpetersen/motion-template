//
//  PXSVGLoader.h
//  PXEngine
//
//  Created by Kevin Lindsey on 6/4/12.
//  Copyright (c) 2012 Pixate, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PXShape.h"

@class PXShapeDocument;

/**
 *  PXSVGLoader is used to load SVG files that have been exported by Adobe Illustrator. This does not support any of the
 *  SVG levels or specfications. As such, this loader is likely to fail when loading SVG files generated by hand or by
 *  other tools.
 */
@interface PXSVGLoader : NSObject <NSXMLParserDelegate>

@property (nonatomic) NSURL *URL;

/**
 *  Create a PXScene by loading the SVG file specified by the given URL
 *
 *  @param URL The URL to load
 */
+ (PXShapeDocument *)loadFromURL:(NSURL *)URL;

/**
 *  The class that will be used to load the SVG file.
 */
+ (Class)loaderClass;

/**
 *  The class to use when loading the SVG file. This allows loadFromURL to be used in this class while letting another
 *  class (likely a subclass of this one) to perform the actual processing of the SVG file. This comes into play when a
 *  developer wishes to build upon this class's implementation. A typical use case would be the introduction of a new
 *  element type.
 *
 *  @param class The loader class
 */
+ (void)setLoaderClass:(Class)class;

/**
 *  Add a new selector to be called after the specified element has been processed
 *
 *  @param selector The selector to call when ending processing of an elementName
 *  @param elementName The element name with which to associate the selector
 */
- (void)addEndSelector:(SEL)selector forElement:(NSString *)elementName;

/**
 *  Add a new selector to be called when a specified element is beginning to be processed
 *
 *  @param selector The selector to call when starting processing of an elementName
 *  @param elementName The element name with which to associate the selector
 */
- (void)addStartSelector:(SEL)selector forElement:(NSString *)elementName;

/**
 *  A convenience method that converts a string value to a float
 *
 *  @param attributeValue The value to process
 */
- (CGFloat)numberFromString:(NSString *)attributeValue;

/**
 *  A convenience method that handles most of the common attributes of a shape, such as its stroke and file, for example
 *
 *  @param attributeDict A dictionary of attribute values to process
 *  @param shape The PXShape to which to apply the attributes
 */
- (void)applyStyles:(NSDictionary *)attributeDict forShape:(PXShape *)shape;

/**
 *  Add the specified shape to the PXScene being generated by this class
 *
 *  @param shape A shape to add to the parse results
 */
- (void)addShape:(PXShape *)shape;

@end