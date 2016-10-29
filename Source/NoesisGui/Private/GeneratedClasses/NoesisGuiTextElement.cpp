////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiTextElement.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiTextElement::UNoesisGuiTextElement(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiTextElement::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TextElement* NoesisTextElement = NsDynamicCast<Noesis::Gui::TextElement*>(InNoesisComponent);
	check(NoesisTextElement);
}

void UNoesisGuiTextElement::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TextElement* NoesisTextElement = NsDynamicCast<Noesis::Gui::TextElement*>(NoesisComponent.GetPtr());
	check(NoesisTextElement)


}

void UNoesisGuiTextElement::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TextElement* NoesisTextElement = NsDynamicCast<Noesis::Gui::TextElement*>(NoesisComponent.GetPtr());
	check(NoesisTextElement)


}

