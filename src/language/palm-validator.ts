import type { ValidationAcceptor, ValidationChecks } from "langium";
import type { PalmAstType, Type } from "./generated/ast.js";
import type { PalmServices } from "./palm-module.js";

/**
 * Register custom validation checks.
 */
export function registerValidationChecks(services: PalmServices) {
  const registry = services.validation.ValidationRegistry;
  const validator = services.validation.PalmValidator;
  const checks: ValidationChecks<PalmAstType> = {
    Type: validator.checkPersonStartsWithCapital,
  };
  registry.register(checks, validator);
}

/**
 * Implementation of custom validations.
 */
export class PalmValidator {
  checkPersonStartsWithCapital(t: Type, accept: ValidationAcceptor): void {
    if (t.name) {
      const firstChar = t.name.substring(0, 1);
      if (firstChar.toUpperCase() !== firstChar) {
        accept("warning", "Person name should start with a capital.", {
          node: t,
          property: "name",
        });
      }
    }
  }
}
