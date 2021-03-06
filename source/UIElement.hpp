#pragma once

#include "UI.hpp"

namespace GTA
{
	public interface class UIElement
	{
		void Draw();
		void Draw(System::Drawing::Size offset);

		property bool Enabled
		{
			bool get();
			void set(bool value);
		}
		property System::Drawing::Point Position
		{
			System::Drawing::Point get();
			void set(System::Drawing::Point value);
		}
		property System::Drawing::Color Color
		{
			System::Drawing::Color get();
			void set(System::Drawing::Color value);
		}
	};

	public ref class UIText : public UIElement
	{
	public:
		UIText(System::String ^caption, System::Drawing::Point position, float scale);
		UIText(System::String ^caption, System::Drawing::Point position, float scale, System::Drawing::Color color);
		UIText(System::String ^caption, System::Drawing::Point position, float scale, System::Drawing::Color color, Font font, bool centered);

		virtual property bool Enabled;
		virtual property System::Drawing::Point Position;
		virtual property System::Drawing::Color Color;
		property System::String ^Caption;
		property Font Font;
		property float Scale;
		property bool Centered;

		virtual void Draw();
		virtual void Draw(System::Drawing::Size offset);
	};
	public ref class UIRectangle : public UIElement
	{
	public:
		UIRectangle();
		UIRectangle(System::Drawing::Point position, System::Drawing::Size size);
		UIRectangle(System::Drawing::Point position, System::Drawing::Size size, System::Drawing::Color color);

		virtual property bool Enabled;
		virtual property System::Drawing::Point Position;
		property System::Drawing::Size Size;
		virtual property System::Drawing::Color Color;

		virtual void Draw();
		virtual void Draw(System::Drawing::Size offset);
	};
	public ref class UIContainer : public UIRectangle
	{
	public:
		UIContainer();
		UIContainer(System::Drawing::Point position, System::Drawing::Size size);
		UIContainer(System::Drawing::Point position, System::Drawing::Size size, System::Drawing::Color color);

		property System::Collections::Generic::List<UIElement ^> ^Items
		{
			System::Collections::Generic::List<UIElement ^> ^get();
			void set(System::Collections::Generic::List<UIElement ^> ^value);
		}

		virtual void Draw() override;
		virtual void Draw(System::Drawing::Size offset) override;

	private:
		System::Collections::Generic::List<UIElement ^> ^mItems;
	};
}