import { defineConfig } from "astro/config";
import starlight from "@astrojs/starlight";

// https://astro.build/config
export default defineConfig({
  integrations: [
    starlight({
      title: "👾 pacos.sh",
      social: {
        github: "https://github.com/pyrossh/pacos.sh",
      },
      sidebar: [
        {
          label: "Basic Types",
          link: "/primitive-types",
        },
        {
          label: "Reference Types",
          link: "/reference-types",
        },
        {
          label: "Declarations",
          items: [
            { label: "Records", link: "/declarations/records" },
            { label: "Traits", link: "/declarations/traits" },
            { label: "Enum", link: "/declarations/enum" },
            { label: "Type Alias", link: "/declarations/aliases" },
            { label: "Functions", link: "/declarations/functions" },
          ],
        },
        {
          label: "Statements",
          items: [
            { label: "Constants", link: "/statements/constants" },
            { label: "Variables", link: "/statements/variables" },
            { label: "If", link: "/statements/if" },
            { label: "While", link: "/statements/while" },
            { label: "For", link: "/statements/for" },
            { label: "Match", link: "/statements/match" },
          ],
        },
        {
          label: "Operators",
          link: "/operators/logical",
        },
        {
          label: "Comments/Documentation",
          link: "/operators/logical",
        },
      ],
    }),
  ],
});
