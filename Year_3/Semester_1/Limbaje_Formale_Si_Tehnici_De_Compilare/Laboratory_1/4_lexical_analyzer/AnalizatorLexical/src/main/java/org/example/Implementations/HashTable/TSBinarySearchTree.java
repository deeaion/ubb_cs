package org.example.Implementations.HashTable;

import org.example.TSValue;
import java.util.ArrayList;
import java.util.List;

public class TSBinarySearchTree {

    private class NodeBST {
        TSValue value;
        NodeBST left;
        NodeBST right;

        public NodeBST(TSValue value) {
            this.value = value;
        }
    }

    private NodeBST root;
    private int currentIndex = 0;  // This tracks the unique position for each inserted node

    // Constructor for an empty BST
    public TSBinarySearchTree() {
        this.root = null;
    }

    // Custom comparison function that compares numeric strings as numbers and non-numeric strings lexicographically
    private int customCompare(String value1, String value2) {
        // Check if both values are numeric
        if (isNumeric(value1) && isNumeric(value2)) {
            // Parse as Double and compare numerically
            Double num1 = Double.parseDouble(value1);
            Double num2 = Double.parseDouble(value2);
            return num1.compareTo(num2);
        }

        // Fall back to lexicographical comparison if both are not numeric
        return value1.compareTo(value2);
    }

    // Helper method to check if a string is numeric
    private boolean isNumeric(String str) {
        try {
            Double.parseDouble(str);  // Try parsing it as a double
            return true;
        } catch (NumberFormatException e) {
            return false;  // If parsing fails, it's not numeric
        }
    }

    public int insert(TSValue value) {
        // Only assign the root once
        if (root == null) {
            root = new NodeBST(value);
            value.setPosition(currentIndex++);
            return value.getPosition();
        } else {
            return insertRecursive(root, value);
        }
    }

    private int insertRecursive(NodeBST node, TSValue value) {

        String newValue = value.getValue();
        String nodeValue = node.value.getValue();

        int comparisonResult = customCompare(newValue, nodeValue);

        if (comparisonResult < 0) {
            // if smaller go left
            if (node.left == null) {
                node.left = new NodeBST(value);
                value.setPosition(currentIndex++);
                return value.getPosition();
            } else {
                return insertRecursive(node.left, value);
            }
        } else if (comparisonResult > 0) {
            // if greater go right
            if (node.right == null) {
                node.right = new NodeBST(value);
                value.setPosition(currentIndex++);
                return value.getPosition();
            } else {
                return insertRecursive(node.right, value);
            }
        } else {
           // if equal, return the existing position
            return node.value.getPosition();
        }
    }


    public TSValue get(String name) {
        return getRecursive(root, name);
    }


    private TSValue getRecursive(NodeBST node, String name) {
        if (node == null) {
            return null;  // Not found
        }

        if (name.equals(node.value.getValue())) {
            return node.value;
        } else if (name.compareTo(node.value.getValue()) < 0) {
            return getRecursive(node.left, name);  // Search in the left subtree
        } else {
            return getRecursive(node.right, name);  // Search in the right subtree
        }
    }


    public List<TSValue> getValues() {
        List<TSValue> values = new ArrayList<>();
        inOrderTraversal(root, values);
        return values;
    }

    private void inOrderTraversal(NodeBST node, List<TSValue> values) {
        if (node != null) {
            inOrderTraversal(node.left, values);
            values.add(node.value);
            inOrderTraversal(node.right, values);
        }
    }
}
