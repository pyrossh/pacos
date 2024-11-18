package tree_sitter_plum_test

import (
	"testing"

	tree_sitter "github.com/smacker/go-tree-sitter"
	"github.com/tree-sitter/tree-sitter-plum"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_plum.Language())
	if language == nil {
		t.Errorf("Error loading plum grammar")
	}
}
