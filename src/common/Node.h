//
//  Node.h
//  TikZiT
//  
//  Copyright 2010 Aleks Kissinger. All rights reserved.
//  
//  
//  This file is part of TikZiT.
//  
//  TikZiT is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//  
//  TikZiT is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//  
//  You should have received a copy of the GNU General Public License
//  along with TikZiT.  If not, see <http://www.gnu.org/licenses/>.
//  


// Node : store the data associated with a node.

#import <Foundation/Foundation.h>

#import "NodeStyle.h"
#import "GraphElementData.h"

/*!
 @class Node
 @brief A graph node, with associated location and style data.
 */
@interface Node : NSObject {
	NSPoint point;
	NodeStyle *style;
	NSString *name;
	NSString *label;
	GraphElementData *data;
}

/*!
 @property   point
 @brief      The point where this node is located.
 */
@property (assign) NSPoint point;

/*!
 @property   style
 @brief      The style of this node.
 */
@property (retain) NodeStyle *style;

/*!
 @property   name
 @brief      The name of this node. This is a temporary name and may change between
             successive TikZ outputs.
 */
@property (copy) NSString *name;

/*!
 @property   label
 @brief      The latex label that appears on this node.
 */
@property (copy) NSString *label;

/*!
 @property   data
 @brief      Associated extra data.
 */
@property (copy) GraphElementData *data;

/*!
 @brief      Initialize a new node with the given point.
 @param      p a point.
 @result     A node.
 */
- (id)initWithPoint:(NSPoint)p;

/*!
 @brief      Initialize a new node at (0,0).
 @result     A node.
 */
- (id)init;

/*!
 @brief      Try to attach a style of the correct name from the given style list.
 @param      styles an array of styles.
 @result     YES if successfully attached, NO otherwise.
 */
- (BOOL)attachStyleFromTable:(NSArray*)styles;

/*!
 @brief      Set node properties from <tt>GraphElementData</tt>.
 */
- (void)updateData;

/*!
 @brief      Copy this node.
 @result     A copy of this node.
 */
- (id)copy;

/*!
 @brief      Set properties of this node to match the given node.
 @param      nd a node to mimic.
 */
- (void)setPropertiesFromNode:(Node *)nd;

/*!
 @brief      Compare a node to another node using a lex ordering on coordinates.
 @param      nd another node.
 @result     A comparison result.
 */
- (NSComparisonResult)compareTo:(id)nd;

/*!
 @brief      Factory method to construct a node with the given point.
 @param      p a point.
 @result     A node.
 */
+ (Node*)nodeWithPoint:(NSPoint)p;

/*!
 @brief      Factory method to construct a node at (0,0).
 @result     A node.
 */
+ (Node*)node;

@end

// vi:ft=objc:noet:ts=4:sts=4:sw=4
